cmake_minimum_required(VERSION 3.1)
project("htts")
set(LIB_NAME htts)
set(LIB_CERENCE_NAME sal_cr)
set(LIB_VOICEWARE_NAME sal_vw)
set(LIB_HOUNDIFYTTS_NAME sal_ht)
set(LIB_BAIDU_NAME sal_bdtts)
set(PROJECT_DESCRIPTION "HTTS Library")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 여기에 MACHINE NAME 을 외부에서 적용해야함. 정의가 안되어있으면, default로 yocto 빌드로 함.
if(NOT CCOS_MACHINE_NAME)
  set(CCOS_MACHINE_NAME "mst6g")
endif()

# default로 aarch64로 설정.
if(NOT CCOS_TARGET_ARCH)
  set(CCOS_TARGET_ARCH "aarch64")
endif()

if(YOCTO_BUILD)
  message("yocto build!!!")
else(YOCTO_BUILD)
  message("not yocto build!!!")
endif(YOCTO_BUILD)

if(NOT DEFINED SANITIZER_BUILD)
  set(SANITIZER_BUILD false)
endif()

if(${SANITIZER_BUILD})
  add_definitions(-DSANITIZER_BUILD)
  set(SANITIZER_CFLAGS -fno-omit-frame-pointer -fsanitize=leak)
  set(SANITIZER_LDFLAGS -fsanitize=leak)
endif()

if(NOT CCOS_LIB_VERSION)
  if(DEFINED ENV{CCOS_LIB_VERSION})
    set(CCOS_LIB_VERSION "$ENV{CCOS_LIB_VERSION}")
    set(PROJECT_VERSION "$ENV{CCOS_LIB_VERSION}")
  else()
    message(
      FATAL_ERROR
        "add build option : \n -DCCOS_LIB_VERSION=X.X.X or export CCOS_LIB_VERSION=X.X.X"
    )
  endif()
endif()

string(REPLACE "." ";" VERSION_LIST ${CCOS_LIB_VERSION})
list(GET VERSION_LIST 0 LIB_MAJOR_VERSION)
list(GET VERSION_LIST 1 LIB_MINOR_VERSION)
list(GET VERSION_LIST 2 LIB_PATCH_VERSION)
set(LIB_VERSION "${CCOS_LIB_VERSION}")
set(PROJECT_VERSION "${CCOS_LIB_VERSION}")

# add rpath for baidu lib
if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  set(CMAKE_INSTALL_RPATH "/ccos/lib/baidu")
endif()

include(FindPkgConfig)
add_library(${LIB_NAME} SHARED "")
add_library(${LIB_CERENCE_NAME} SHARED "")
add_library(${LIB_VOICEWARE_NAME} SHARED "")
if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  add_library(${LIB_HOUNDIFYTTS_NAME} SHARED "")
  add_library(${LIB_BAIDU_NAME} SHARED "")
endif()

if(${CCOS_MACHINE_NAME} STREQUAL "ubuntu")
  set(HCOMMON_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/external/library/HCommon/include)
  set(HUTIL_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/external/library/HUtil/include)
  set(HUTIL_LDFLAGS -L/ccos/lib hutil)
else()
  pkg_check_modules(HCOMMON REQUIRED hcommon)
  pkg_check_modules(HUTIL REQUIRED hutil)
endif()

if(${RUN_UNITTEST})
  # yocto 빌드할때는 coverage 체크하는 플래그를 제거한다.
  set(GCOV_CFLAGS -fprofile-arcs -ftest-coverage)
  set(GCOV_LDFLAGS gcov)
endif()

add_subdirectory(TTSLogger)
add_subdirectory(test)

target_include_directories(
  ${LIB_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include ${HCOMMON_INCLUDE_DIRS}
         ${PROJECT_SOURCE_DIR}/external/library/nlohmann-json/include
         ${PROJECT_SOURCE_DIR}/TTSLogger)

target_include_directories(
  ${LIB_CERENCE_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/porting
    ${PROJECT_SOURCE_DIR}/external/library/nlohmann-json/include
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_prompter
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_audio
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_audio_module_output
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_common
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_cloudservices
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/pal
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_audio_module_to_file
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_audio_module_encoder
    ${PROJECT_SOURCE_DIR}/external/library/cerence/include/nds_audio_module_src
    ${PROJECT_SOURCE_DIR}/TTSLogger)

target_include_directories(
  ${LIB_VOICEWARE_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
         ${PROJECT_SOURCE_DIR}/external/library/nlohmann-json/include
         ${PROJECT_SOURCE_DIR}/external/library/voiceware/include
         ${PROJECT_SOURCE_DIR}/TTSLogger)

if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  target_include_directories(
    ${LIB_HOUNDIFYTTS_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
           ${PROJECT_SOURCE_DIR}/external/library/nlohmann-json/include
           ${PROJECT_SOURCE_DIR}/external/library/houndifytts/include
           ${PROJECT_SOURCE_DIR}/TTSLogger)

  target_include_directories(
    ${LIB_BAIDU_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
           ${PROJECT_SOURCE_DIR}/external/library/nlohmann-json/include
           ${PROJECT_SOURCE_DIR}/external/library/bdtts/include/tts
           ${PROJECT_SOURCE_DIR}/TTSLogger)
endif()

target_sources(
  ${LIB_NAME}
  PRIVATE ${PROJECT_SOURCE_DIR}/src/HTts.cpp
          ${PROJECT_SOURCE_DIR}/src/HTtsUtil.cpp
          ${PROJECT_SOURCE_DIR}/src/HTtsInitializeArgument.cpp
          ${PROJECT_SOURCE_DIR}/src/HTtsEngineInfo.cpp
          ${PROJECT_SOURCE_DIR}/src/HTtsFrameInfo.cpp
          ${PROJECT_SOURCE_DIR}/src/HTtsPrompterArgument.cpp
          ${PROJECT_SOURCE_DIR}/src/HTtsSynthesizeArgument.cpp
  INTERFACE ${PROJECT_SOURCE_DIR}/include/HTts.h
            ${PROJECT_SOURCE_DIR}/include/HTtsCommon.h
            ${PROJECT_SOURCE_DIR}/include/IHTtsListener.h)

target_sources(
  ${LIB_CERENCE_NAME}
  PRIVATE ${PROJECT_SOURCE_DIR}/porting/CerenceAudioOutputFactory.cpp
          ${PROJECT_SOURCE_DIR}/porting/CerenceAudioOutputAdapter.cpp
          ${PROJECT_SOURCE_DIR}/porting/CerencePrompterListener.cpp
          ${PROJECT_SOURCE_DIR}/porting/CerencePromptListener.cpp
          ${PROJECT_SOURCE_DIR}/porting/CerenceHandler.cpp
          ${PROJECT_SOURCE_DIR}/porting/PortingTtsCerence.cpp)

target_sources(${LIB_VOICEWARE_NAME}
               PRIVATE ${PROJECT_SOURCE_DIR}/porting/PortingTtsVoiceware.cpp)

if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  target_sources(${LIB_HOUNDIFYTTS_NAME}
                 PRIVATE ${PROJECT_SOURCE_DIR}/porting/PortingTtsHoundify.cpp)

  target_sources(${LIB_BAIDU_NAME}
                 PRIVATE ${PROJECT_SOURCE_DIR}/porting/PortingTtsBaidu.cpp)
endif()

target_compile_options(${LIB_NAME} PRIVATE -Wall -Werror ${GCOV_CFLAGS}
                                           ${SANITIZER_CFLAGS})
target_compile_options(${LIB_CERENCE_NAME} PRIVATE -Wall -Werror ${GCOV_CFLAGS}
                                                   ${SANITIZER_CFLAGS})
target_compile_options(${LIB_VOICEWARE_NAME}
                       PRIVATE -Wall -Werror ${GCOV_CFLAGS} ${SANITIZER_CFLAGS})

if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  target_compile_options(
    ${LIB_HOUNDIFYTTS_NAME} PRIVATE -Wall -Werror ${GCOV_CFLAGS}
                                    ${SANITIZER_CFLAGS})
  target_compile_options(${LIB_BAIDU_NAME} PRIVATE -Wall -Werror ${GCOV_CFLAGS}
                                                   ${SANITIZER_CFLAGS})
endif()

if(${CCOS_MACHINE_NAME} STREQUAL "ubuntu" OR ${CCOS_MACHINE_NAME} STREQUAL
                                             "qemux86-64")
  # CCOS_TARGET_ARCH 이게 yocto 빌드할때, qemu하면 x86_64로 오나? 그걸 몰라서 MACHINE_NAME을 기준으로
  # 함.
  set(VOICEWARE_LIBRARY_DIRS
      ${PROJECT_SOURCE_DIR}/external/library/voiceware/libs/x86_linux64/)
  set(CERENCE_LIBRARY_DIRS
      ${PROJECT_SOURCE_DIR}/external/library/cerence/libs/x86_linux64/)
else()
  set(VOICEWARE_LIBRARY_DIRS
      ${PROJECT_SOURCE_DIR}/external/library/voiceware/libs/arm_linux/)
  set(CERENCE_LIBRARY_DIRS
      ${PROJECT_SOURCE_DIR}/external/library/cerence/libs/arm_linux/)
  set(HOUNDIFYTTS_LIBRARY_DIRS
      ${PROJECT_SOURCE_DIR}/external/library/houndifytts/libs/arm_linux/)
  set(BAIDU_LIBRARY_DIRS
      -L${PROJECT_SOURCE_DIR}/external/library/bdtts/libs/arm_linux/
      -L${PROJECT_SOURCE_DIR}/external/library/bdtts/extern/libs/arm_linux/)
endif()

target_link_libraries(${LIB_NAME} ${HCOMMON_LDFLAGS} ${SANITIZER_LDFLAGS}
                      ${GCOV_LDFLAGS} dl ttsLogger)

target_link_libraries(
  ${LIB_VOICEWARE_NAME}
  ${GCOV_LDFLAGS}
  ${SANITIZER_LDFLAGS}
  -L${VOICEWARE_LIBRARY_DIRS}
  -pthread
  vt_kor_t
  pthread
  ttsLogger)

target_link_libraries(
  ${LIB_CERENCE_NAME}
  ${GCOV_LDFLAGS}
  ${SANITIZER_LDFLAGS}
  -L${CERENCE_LIBRARY_DIRS}
  nds_prompter
  nds_prompter_c
  ve
  nds_audio
  nds_audio_c
  nds_audio_module_output
  nds_audio_module_output_c
  dd_common
  dd_common_c
  nds_audio_module_from_file
  nds_cloudservices
  nds_cloudservices_c
  vocon_curl
  pal_core
  nds_audio_module_to_file
  nds_audio_module_to_file_c
  nds_audio_module_encoder
  nds_audio_module_encoder_c
  nds_audio_module_src
  nds_audio_module_src_c
  asound
  ttsLogger)

if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  target_link_libraries(
    ${LIB_HOUNDIFYTTS_NAME}
    ${GCOV_LDFLAGS}
    ${SANITIZER_LDFLAGS}
    -L${HOUNDIFYTTS_LIBRARY_DIRS}
    -pthread
    HoundifyTTS
    pthread
    ttsLogger)

  target_link_libraries(
    ${LIB_BAIDU_NAME}
    ${GCOV_LDFLAGS}
    ${SANITIZER_LDFLAGS}
    ${BAIDU_LIBRARY_DIRS}
    -pthread
    ccnc_tts
    BDSpeechSDK
    AudioDecoder
    AudioEncoder
    bd_tiny_easr
    esis-wkp
    iconv
    vad
    ttsLogger
    pthread)
endif()

set_target_properties(${LIB_NAME} PROPERTIES VERSION ${LIB_VERSION}
                                             SOVERSION ${LIB_MAJOR_VERSION})
set_target_properties(
  ${LIB_CERENCE_NAME} PROPERTIES VERSION ${LIB_VERSION} SOVERSION
                                                        ${LIB_MAJOR_VERSION})
set_target_properties(
  ${LIB_VOICEWARE_NAME} PROPERTIES VERSION ${LIB_VERSION} SOVERSION
                                                          ${LIB_MAJOR_VERSION})
if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  set_target_properties(
    ${LIB_HOUNDIFYTTS_NAME} PROPERTIES VERSION ${LIB_VERSION}
                                       SOVERSION ${LIB_MAJOR_VERSION})
  set_target_properties(
    ${LIB_BAIDU_NAME} PROPERTIES VERSION ${LIB_VERSION} SOVERSION
                                                        ${LIB_MAJOR_VERSION})
endif()

install(
  FILES ${PROJECT_SOURCE_DIR}/include/HTts.h
        ${PROJECT_SOURCE_DIR}/include/IHTtsListener.h
        ${PROJECT_SOURCE_DIR}/include/HTtsTypes.h
        ${PROJECT_SOURCE_DIR}/include/HTtsEngineInfo.h
        ${PROJECT_SOURCE_DIR}/include/HTtsFrameInfo.h
        ${PROJECT_SOURCE_DIR}/include/HTtsInitializeArgument.h
        ${PROJECT_SOURCE_DIR}/include/HTtsSynthesizeArgument.h
        ${PROJECT_SOURCE_DIR}/include/HTtsPrompterArgument.h
  DESTINATION ${CCOS_INC_DIR})

install(TARGETS ${LIB_NAME} LIBRARY DESTINATION ${CCOS_LIB_DIR})

install(TARGETS ${LIB_CERENCE_NAME} LIBRARY DESTINATION ${CCOS_LIB_DIR})
install(TARGETS ${LIB_VOICEWARE_NAME} LIBRARY DESTINATION ${CCOS_LIB_DIR})
if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
  install(TARGETS ${LIB_HOUNDIFYTTS_NAME} LIBRARY DESTINATION ${CCOS_LIB_DIR})
  install(TARGETS ${LIB_BAIDU_NAME} LIBRARY DESTINATION ${CCOS_LIB_DIR})
endif()

configure_file(pkgconfig/ccos2.pc.in htts.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/htts.pc DESTINATION ${CCOS_LIB_DIR}/pkgconfig)

if(${SELVAS_BUILD})
  # 필요시 사용
  install(
    DIRECTORY ${VOICEWARE_LIBRARY_DIRS}
    DESTINATION ${CCOS_LIB_DIR}
    PATTERN "*.so")
  install(
    DIRECTORY ${CERENCE_LIBRARY_DIRS}
    DESTINATION ${CCOS_LIB_DIR}
    PATTERN "*.so")
  if(${CCOS_TARGET_ARCH} STREQUAL "aarch64")
    install(
      DIRECTORY ${HOUNDIFYTTS_LIBRARY_DIRS}
      DESTINATION ${CCOS_LIB_DIR}
      PATTERN "*.so")
    install(
      DIRECTORY ${BAIDU_LIBRARY_DIRS}
      DESTINATION ${CCOS_LIB_DIR}
      PATTERN "*.so")
  endif()
endif()

if(YOCTO_BUILD)
  message("-- build_version : ${VERSION}")
  add_definitions(-DBUILD_VERSION=\"${VERSION}\")
else(YOCTO_BUILD)
  execute_process(
    COMMAND git describe --tags --abbrev=0
    OUTPUT_VARIABLE GIT_REV
    ERROR_QUIET ${GIT_REV} OUTPUT_STRIP_TRAILING_WHITESPACE)
  message("-- build_version : ${GIT_REV}")
  add_definitions(-DBUILD_VERSION=\"${GIT_REV}\")
endif(YOCTO_BUILD)

execute_process(
  COMMAND date
  OUTPUT_VARIABLE BUILD_DATE
  ERROR_QUIET ${BUILD_DATE} OUTPUT_STRIP_TRAILING_WHITESPACE)
message("-- build_date : ${BUILD_DATE}")
add_definitions(-DBUILD_DATE=\"${BUILD_DATE}\")

