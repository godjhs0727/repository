#include <stdio.h>
#include <Windows.h>

int main()
{
	//변수 : 앞으로 어떻게 변할지 알 수 없는 수 & 값을 저장하기 위한 메모리 공간
	int a; //변수의 선언, int : DataType(자료형)
	
	a = -5; //변수의 초기화(Initialze)
	a = 20; //변수의 초기화(Initialze)
	a = 2000000000;
	printf("a에 대입된 수는 %d 입니다.\n", a);

	float fNumber; //float : 실수를 저장하는 타입. 4 Bytes
	fNumber = 3.14f;
	printf("fNumber에 대입된 수는 %.2f 입니다.\n", fNumber);

	//변수들을 선언하는 부분
	double dNumber; //실수, 8 Bytes
	long lNumber; //정수, 4 Bytes
	long long llNumber; //정수, 8 Bytes
	char ascii; //문자(알파벳 한글자)
	bool isDead; //참(1 true), 거짓(0, false), 1Byte

	unsigned int violent; //
	violent = -1;
	printf("간디의 폭력성은 %u\n", violent);

	int weWantedName;
	//작명 규칙
	// -> 대소문자 구별
	// -> 한번 선언된 변수는 같은 함수 내에서 다시 재선언이 불가능함
	// -> 변수명 맨 앞에는 숫자 불가
	// -> 특수문자 불가 (_ 는 가능)
	// -> 이미 예약된 키워드는 사용 불가
	// -> 띄워쓰기 불가

	int player1CurrentHp; //Camel
	int player1_current_hp; //Snake
	
	
	system("pause");
	return 0;
}