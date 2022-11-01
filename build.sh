#!/bin/bash

showHelp() {
    cat <<EOF
Usage: ./build.sh [-hciubt] <VARIABLE>

-h, -help, --help                  Display help
-c, -clean, --clean                Clean Build
-i, -install, --install            Install
-u, -unittest, --unittest          Run UnitTest
-t, -type, --type                  Build Type (x64, arm, codesonar, qemu, sanitizer)
-b, -binary, --binary              target only binary push (*.so, exe) - default all resource push (header, pcm, etc..)
EOF
    exit 1
}

applyX64Environment() {
    export PKG_CONFIG_PATH="$PKG_CONFIG_PATH:/ccos/lib/pkgconfig"
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/ccos/lib"
    export PATH=/usr/lib/ccache:$PATH
}

applyQEMUEnvironment() {
    unset PKG_CONFIG_PATH
    unset LD_LIBRARY_PATH
    . /usr/local/oecore-qemu-x86_64/environment-setup-core2-64-gnu-linux
    export PATH=/usr/lib/ccache:$PATH
}

applyARMEnvironment() {
    unset PKG_CONFIG_PATH
    unset LD_LIBRARY_PATH
    . /usr/local/oecore-x86_64/environment-setup-aarch64-gnu-linux
    export PATH=/usr/lib/ccache:$PATH
}

boardSetup() {
    if [[ -z "${HMC_BOARD_IP}" ]]; then
        echo "ERROR: HMC_BOARD_IP Environment variable is not set"
        exit 1
    fi

    ssh root@${HMC_BOARD_IP} mount -o rw,remount /
    ssh root@${HMC_BOARD_IP} mount -o rw,remount /ccos/data/vr
    ssh root@${HMC_BOARD_IP} mount -o rw,remount /ccos/vr || true
    ssh root@${HMC_BOARD_IP} date -s \"2021-7-30 09:00:00\"
}

boardBeforeInstall() {
    echo "boardBeforeInstall"
}

boardAfterInstall() {
    echo "boardAfterInstall"
}

# 21.12.30 현재는 TEST_F 만 Count 하게 해놓음  (이유는 기존 htts_unittest.cpp 까지 카운트하고있어서.)
# by bruno.
declare -i TC_COUNT=$(find . -type f -regextype sed -regex ".*\(t\|T\)est.cpp" -exec egrep -Hn "^TEST_F?" {} \; | wc -l)

BUILD_ROOT=$PWD

options=$(getopt -l "help,clean,install,type:,unittest,binary" -o "hcit:ub" -a -- "$@")
eval set -- "$options"

BUILD_TYPE="unknown"
BUILD_CLEAN=false
BUILD_INSTALL=false
RUN_UNITTEST=false
RUN_JENKINS=false
INSTALL_BINARY=true

if [ "$(whoami)" != "jenkins" ]; then
# if [[ -z "${SUDO_USER}" ]]; then
    echo "@ normal shell build @"
else
    echo "@ jenkins shell build @"
    RUN_JENKINS=true
fi

err_msg() { echo "$@"; } >&2
err_msg_type() { err_msg "-s option argument x64, arm, codesonar or sanitizer required"; }

while true; do
    case $1 in
    -h | --help)
        showHelp
        shift
        ;;
    -t | --type)
        [ "$2" = "x64" ] || [ "$2" = "arm" ] || [ "$2" = "codesonar" ] || [ "$2" = "sanitizer" ] || [ "$2" = "qemu" ] || {
            err_msg_type
            showHelp
        }
        BUILD_TYPE=$2

        if [ "$2" == "codesonar" ]; then
            BUILD_CLEAN=true
        fi

        if [ "$2" == "deb" ]; then
        # 21.12.30 이전에는 직접 deb패키지 올렸었는데, 지금은 코드를 올린다고함. 
            BUILD_CLEAN=true
            echo "No longer supported.(2021.12.30 by bruno)"
            exit 1
        fi
        shift 2
        ;;
    -c | --clean)
        BUILD_CLEAN=true
        shift
        ;;
    -i | --install)
        BUILD_INSTALL=true
        shift
        ;;
    -u | --unittest)
        RUN_UNITTEST=true
        shift
        ;;
    -b | --binary)
        INSTALL_BINARY=false
        shift
        ;;
    --)
        break
        ;;
    esac
done

if [ ${BUILD_TYPE} == "unknown" ]; then
    showHelp
    exit 1
fi

./CodeValidate.sh

BUILD_DIR="${PWD}/build_${BUILD_TYPE}"

echo "@@@ BUILD_TYPE             : $BUILD_TYPE"
echo "@@@ BUILD_ROOT             : $BUILD_ROOT"
echo "@@@ BUILD_DIR              : $BUILD_DIR"
echo "@@@ BUILD_CLEAN            : $BUILD_CLEAN"
echo "@@@ BUILD_INSTALL          : $BUILD_INSTALL"
echo "@@@ RUN_UNITTEST           : $RUN_UNITTEST"
echo "@@@ RUN_JENKINS            : $RUN_JENKINS"
echo "#######################################################"

if [ ${BUILD_CLEAN} == true ]; then
    echo "!!! CLEAN BUILD_DIR !!! : $BUILD_DIR"
    echo "#######################################################"

    rm -rf $BUILD_DIR
fi

mkdir $BUILD_DIR 2>/dev/null
cd $BUILD_DIR


CCOS_LIB_DIR=/ccos/lib
CCOS_INC_DIR=/ccos/include/htts
CCOS_INTERFACE_DIR=/ccos/interfaces/htts
CCOS_MACHINE_NAME=mst6g # ubuntu, mst6g, qemux86-64
CCOS_LIB_VERSION=2.0.0
CMAKE_LOCATE=".."
MAKE_PREFIX=""

# https://github.com/Selvas-AI/VRMW/issues/29#issuecomment-1024359532
CCOS_TARGET_ARCH=aarch64 # x86_64, aarch64 

function print_ut_result {
    CURRENT=""
    PASSED=()
    FAILED=()
    ERRORED=()
    PASSED_COUNT=0
    FAILED_COUNT=0
    TOTAL_COUNT=$2

    while IFS= read -r line; do
        if [[ $line =~ \[[[:space:]]{1}RUN[[:space:]]{6}\] ]]; then
            if [[ ! -z $CURRENT ]]; then
                echo "something wrong at $CURRENT"
                ERRORED+=($CURRENT)
            fi
            CURRENT=$(echo $line | xargs echo $(awk '{print $4}'))
        elif [[ $line =~ \[[[:space:]]{7}OK[[:space:]]{1}\].*ms ]]; then
            TC=$(echo $line | xargs echo $(awk '{print $4}'))
            if [[ -z $CURRENT || ! $CURRENT == $TC ]]; then
                echo "something wrong at $CURRENT and $TC"
                ERRORED+=($CURRENT $TC)
            else
                PASSED+=($CURRENT)
                PASSED_COUNT=$(($PASSED_COUNT + 1))
            fi
            CURRENT=""
        elif [[ $line =~ \[[[:space:]]{2}FAILED[[:space:]]{2}\].*ms ]]; then
            TC=$(echo $line | xargs echo $(awk '{print $4}'))
            if [[ -z $CURRENT || ! $CURRENT == $TC ]]; then
                echo "something wrong at $CURRENT and $TC"
                ERRORED+=($CURRENT $TC)
            else
                FAILED+=($CURRENT)
                FAILED_COUNT=$(($FAILED_COUNT + 1))
            fi
            CURRENT=""
        else
            echo "something wrong at $CURRENT"
            ERRORED+=($CURRENT $TC)
            CURRENT=""
        fi
    done < <(grep -P --color=always "(^\[[[:space:]]{2}FAILED[[:space:]]{2}\].*ms|^\[[[[:space:]]{7}OK[[[:space:]]{1}\]|^\[[[[:space:]]{1}RUN[[[:space:]]{6}\])" $1)

    echo "* PASSED list - #${PASSED_COUNT}"
    echo "* FAILED list - #${FAILED_COUNT}"
    for f in ${FAILED[@]}; do
        echo -e "\t $f "
    done
    echo "* ERRORED - #${#ERRORED[@]}"
    for f in ${ERRORED[@]}; do
        echo -e "\t $f "
    done

    # 언어별 특이케이스를 카운트하는걸 어떻게할지 고민이 필요함.
    # RUN_CNT=$(($PASSED_COUNT + $FAILED_COUNT))
    # if [ $RUN_CNT -ne $TOTAL_COUNT ]; then
    #     echo -e "\n\n!!! TC count not $TOTAL_COUNT !!!\n\n"
    #     lastLine=$(tail -1 $1)
    #     echo -e "\n\tsee last line of the log...\n"
    #     echo -e "$lastLine\n\n"
    #     return -1
    # fi
}

# preinst
if [ ${BUILD_TYPE} == "x64" ]; then
    applyX64Environment
    CCOS_MACHINE_NAME=ubuntu
    CCOS_TARGET_ARCH=x86_64
    if [ ${RUN_UNITTEST} == true ]; then
        EXTRA_DEFINE="${EXTRA_DEFINE} -DRUN_UNITTEST=true"
    fi
elif [ ${BUILD_TYPE} == "qemu" ]; then
    applyQEMUEnvironment
    CCOS_MACHINE_NAME=qemux86-64
    CCOS_TARGET_ARCH=x86_64
    CCOS_INSTALL_PREFIX=$OECORE_TARGET_SYSROOT
    CCOS_INC_DIR=$CCOS_INSTALL_PREFIX$CCOS_INC_DIR
    CCOS_LIB_DIR=$CCOS_INSTALL_PREFIX$CCOS_LIB_DIR
    CCOS_INTERFACE_DIR=$CCOS_INSTALL_PREFIX$CCOS_INTERFACE_DIR
elif [ ${BUILD_TYPE} == "arm" ]; then
    applyARMEnvironment
    CCOS_MACHINE_NAME=mst6g
    CCOS_TARGET_ARCH=aarch64
    if [ ${RUN_UNITTEST} == true ]; then
        EXTRA_DEFINE="${EXTRA_DEFINE} -DRUN_UNITTEST=true"
    fi
    CCOS_INSTALL_PREFIX=$OECORE_TARGET_SYSROOT
    CCOS_INC_DIR=$CCOS_INSTALL_PREFIX$CCOS_INC_DIR
    CCOS_LIB_DIR=$CCOS_INSTALL_PREFIX$CCOS_LIB_DIR
    CCOS_INTERFACE_DIR=$CCOS_INSTALL_PREFIX$CCOS_INTERFACE_DIR
elif [ ${BUILD_TYPE} == "codesonar" ]; then
    applyARMEnvironment
    mkdir htts_arm 2>/dev/null
    cd htts_arm
    CMAKE_LOCATE="../.."
    MAKE_PREFIX="codesonar analyze $PWD -clean -foreground -no-services -conf-file $BUILD_ROOT/STD_Gen6_CPU.conf 10.230.112.180:7341"
elif [ ${BUILD_TYPE} == "sanitizer" ]; then
    applyX64Environment
    CCOS_MACHINE_NAME=ubuntu
    EXTRA_DEFINE="-DSANITIZER_BUILD=true -DARM_BUILD=false"
fi

echo "@@@ CCOS_LIB_DIR           : $CCOS_LIB_DIR"
echo "@@@ CCOS_INC_DIR           : $CCOS_INC_DIR"
echo "@@@ CCOS_INTERFACE_DIR     : $CCOS_INTERFACE_DIR"
echo "@@@ CCOS_LIB_VERSION       : $CCOS_LIB_VERSION"
echo "@@@ CCOS_MACHINE_NAME       : $CCOS_MACHINE_NAME"
echo "@@@ CCOS_TARGET_ARCH       : $CCOS_TARGET_ARCH"
echo "@@@ EXTRA_DEFINE           : $EXTRA_DEFINE"
echo "#######################################################"

cmake $CMAKE_LOCATE -DCCOS_LIB_DIR=$CCOS_LIB_DIR -DCCOS_INC_DIR=$CCOS_INC_DIR \
    -DCCOS_INTERFACE_DIR=$CCOS_INTERFACE_DIR -DCCOS_LIB_VERSION=$CCOS_LIB_VERSION $EXTRA_DEFINE \
    -DCCOS_MACHINE_NAME=$CCOS_MACHINE_NAME -DCCOS_TARGET_ARCH=$CCOS_TARGET_ARCH

declare -i cores=$(grep -c ^processor /proc/cpuinfo)
echo $MAKE_PREFIX
$MAKE_PREFIX make -j$cores

if [ "$?" != 0 ]; then
    echo "@@@ [ERROR] make @@@"
    exit 1
fi

if [ ${BUILD_INSTALL} == true ]; then
    if [ ${BUILD_TYPE} == "x64" ]; then
        make install
    elif [ ${BUILD_TYPE} == "qemu" ]; then
        make install
    elif [ ${BUILD_TYPE} == "arm" ]; then
        make install
        if [ ${RUN_JENKINS} == false ]; then
            boardSetup
            boardBeforeInstall

            $BUILD_ROOT/BoardInstaller.sh ./install_manifest.txt $INSTALL_BINARY -e include
            if [ ${RUN_UNITTEST} == false ]; then
                boardAfterInstall
            fi
        fi
    elif [ ${BUILD_TYPE} == "codesonar" ]; then
        echo >/dev/null
    elif [ ${BUILD_TYPE} == "sanitizer" ]; then
        make install
    fi
fi

# read test_language
TEST_FILEPATH=$BUILD_ROOT/test/config/test_language.txt
UNITTEST_STRING=""
COUNT_LANGUAGE=0
GTEST_SAVE_PATH="."
if [ ${BUILD_TYPE} == "arm" ]; then
    GTEST_SAVE_PATH="/ccos/data/tests/htts_gtest/"
fi

while read line || [ -n "$line" ] ; do
  UNITTEST_STRING="${UNITTEST_STRING} /ccos/interfaces/htts/htts-gtest-api --test_language=$line --gtest_output=xml:$GTEST_SAVE_PATH/asr_$line.xml\n"
  ((COUNT_LANGUAGE+=1))
done < $TEST_FILEPATH
TC_COUNT=$(($TC_COUNT * $COUNT_LANGUAGE))

if [ ${RUN_UNITTEST} == true ]; then
    if [ ${BUILD_TYPE} == "x64" ]; then
        lcov -q --capture --initial --directory . --output-file ./htts_base.info
        echo -en "export LD_LIBRARY_PATH=\"$LD_LIBRARY_PATH:/ccos/lib\"
        export GTEST_OUTPUT=\"xml:./\"
        ulimit -c unlimited
        $UNITTEST_STRING
        " >htts_x64_gtest.sh
        chmod +x ./htts_x64_gtest.sh
        ./htts_x64_gtest.sh |& tee ut_full.log.txt

        echo "@@@ make gtest report @@@"
        cp -R $BUILD_ROOT/external/tools/gtest_report .
        cp *.xml ./gtest_report/in/
        cd gtest_report
        ./generate.sh
        cd ..

        lcov -q --capture --directory . --output-file ./htts_test.info
        lcov -q --add-tracefile ./htts_base.info --add-tracefile ./htts_test.info --output-file ./htts_total.info
        lcov -q --remove ./htts_total.info '/usr/*' '*/external/*' '*/test/*' '*/utils/*' -o ./htts_filtered.info
        genhtml -q --prefix . --ignore-errors source ./htts_filtered.info --legend --title "HTTS gtest" --output-directory=./htts_lcov

        echo -e "\n\ngrep ut result at log <${BUILD_DIR}/ut_full.log.txt>"
        echo -e "** start **"
        print_ut_result ut_full.log.txt $TC_COUNT
        if [ $? -ne 0 ]; then
            exit -1
        fi
        echo -e "** end **"
        if [ ${RUN_JENKINS} == false ]; then
            sensible-browser ./gtest_report/out/gtest_report.html &
            sensible-browser ./htts_lcov/index.html
        fi
    elif [ ${BUILD_TYPE} == "arm" ]; then
        depth=${PWD//[!\/]} # *.gcda파일은 절대경로로 생성됨.
        gcov_tool="--gcov-tool /usr/local/oecore-x86_64/sysroots/x86_64-ccos-linux/usr/bin/aarch64-gnu-linux/aarch64-gnu-linux-gcov"
        echo -en "
export GCOV_PREFIX=/ccos/data/tests/htts_gtest/lcov/
export GCOV_PREFIX_STRIP=${#depth}
export DBUS_SESSION_BUS_ADDRESS="unix:path=/var/run/dbus/ccos_session_bus_socket"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/ccos/lib"
$UNITTEST_STRING
ls -lah /ccos/data/tests/htts_gtest/
        " >htts_arm_gtest.sh
        
        rm -rf ./gtest_report >/dev/null
        rm -rf ./htts_lcov > /dev/null

        chmod +x ./htts_arm_gtest.sh
        ssh root@${HMC_BOARD_IP} rm -rf /ccos/data/tests/htts_gtest >/dev/null
        ssh root@${HMC_BOARD_IP} mkdir -p /ccos/data/tests/htts_gtest
        ssh root@${HMC_BOARD_IP} mkdir -p /ccos/data/tests/htts_gtest/lcov
        scp ./htts_arm_gtest.sh root@$HMC_BOARD_IP:/ccos/data/tests/htts_gtest/
        rm -f ut_full.log.txt >/dev/null
        ssh root@${HMC_BOARD_IP} /ccos/data/tests/htts_gtest/htts_arm_gtest.sh | tee ut_full.log.txt
        scp root@$HMC_BOARD_IP:/ccos/data/tests/htts_gtest/*.xml .

        scp -r root@$HMC_BOARD_IP:/ccos/data/tests/htts_gtest/lcov/* ./ # 이건 저장되어있는 디렉토리를 가져오거나 변경이 필요한사항.
        lcov -q --capture --directory . --output-file ./htts_test.info $gcov_tool
        lcov -q --add-tracefile ./htts_test.info --output-file ./htts_total.info $gcov_tool
        lcov -q --remove ./htts_total.info '/usr/*' '*/external/*' '*/test/*' '*/utils/*' -o ./htts_filtered.info $gcov_tool
        genhtml -q --prefix . --ignore-errors source ./htts_filtered.info --legend --title "HTTS gtest" --output-directory=./htts_lcov

        echo "@@@ make gtest report @@@"
        cp -R $BUILD_ROOT/external/tools/gtest_report .
        cp *.xml ./gtest_report/in/
        cd gtest_report
        ./generate.sh
        cd ..
        
        echo -e "\n\ngrep ut result at log <${BUILD_DIR}/ut_full.log.txt>"
        echo -e "** start **"
        print_ut_result ut_full.log.txt $TC_COUNT
        if [ $? -ne 0 ]; then
            exit -1
        fi
        echo -e "** end **"
        if [ ${RUN_JENKINS} == false ]; then
            sensible-browser ./gtest_report/out/gtest_report.html &
            sensible-browser ./htts_lcov/index.html
        fi
    elif [ ${BUILD_TYPE} == "codesonar" ]; then
        echo >/dev/null
    elif [ ${BUILD_TYPE} == "qemu" ]; then
        echo >/dev/null
    elif [ ${BUILD_TYPE} == "sanitizer" ]; then
        cd ../
        python3 sanitizer_check.py
    fi
fi

