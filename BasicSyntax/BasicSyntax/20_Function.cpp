#include <stdio.h>
#include <Windows.h>
#include <time.h>//.h는 c언어때 나온것들
#include <string>
#include <iostream>//h안붙는애들은 c++에서 나온거
using namespace std;

//함수 사용 목적
//-> 1. 코드의 재사용성
//-> 2. 가독성 향상

int WhatIsFunction() // <- 함수의 선언부(Prototype)
{
	//-> 함수의 내용
	printf("함수의 세계에 오신 것을 환영\n");
	
	return 0;//<- 함수의 리턴값
}



int Max(int a, int b)
{
	int max = a > b ? a : b; //삼항 연산자 참이면 앞에 걸리고 거짓이면 뒤에 있는것이 걸리고 a Or b a가 b 보다 크면 a가 걸리고 아니면 b가 걸림
	printf("Max : %d\n", max);

	return 0;
}

int WhatIsReturn(int range)
{
	printf("0~당신이 입력한 수 범위 안에서 랜덤수 하나를 알려드립니다\n");
	srand((UINT)time(NULL));
	int result = rand() % range;

	return result; //*ptr로 쓰려면 함수를 *포인터로 맞춰줘야 한다. int* WhatIsReturn -> int* ptr 가능
}

char ToSwapCharacter(char ascii)
{
	char temp = 'a';

	if (ascii >= 'a' && ascii <= 'z')
		temp = ascii - 32;
	else if (ascii >= 'A' && ascii <= 'Z')
		temp = ascii + 32;
	else
	{
		printf("입력 범위를 벗어나는 값입니다.!\n");
		return ascii;
	}

	return temp;
}

void WhatIsVoid()
{
	printf("1. 나는 리턴이 없습니다! 파라미터는 받을 수 있습니다.\n");
	return; //뒤에 2번이 표시가 되지 않는다.
	printf("2. 나는 리턴이 없습니다! 파라미터는 받을 수 있습니다.\n");
}

string WhatIsPrototype();
void WhatIsPrototype2(); //전구 만들기 ctrl .혹은 alt enter 그리고 정의 만들기

void WhatIsOverloading();//클립보드 복사 붙혀넣기 같은 이름의 함수를 만드는 이유
void WhatIsOverloading(int a); // 함수의 이름은 똑같은데 똑같은 기능을 다르게 사용하기 위해서? 가독성?
void WhatIsOverloading(int a, int b);
void WhatIsOverloading(float a);

template<typename T>//T는 미지의 데이터 타입
void WhatIsTemplate(T val)//템플릿은 모든 데이터타입을 받을수 있어서 그게 오히려 부작용일수 있다.
{
	cout << val << endl;
}

int main()
{

	////함수란?
	//WhatIsFunction(); //<- 함수의 호출(Call)

	////파라미터란?(인자)
	//int input1, input2; //Max 함수로 복사해서 하는 호출 방식 Call By Value
	//printf("숫자1 입력 :");
	//scanf("%d", &input1);
	//printf("숫자2 입력 :");
	//scanf("%d", &input2);

	//Max(input1, input2); //<- 파라미터가 존재하는 함수(인자)
	//Max(7, 9); //%d때문에 숫자만 써도 가능
	//리턴이란?
	//int result = WhatIsReturn(5);
	//printf("%d\n", result);
	//while (true)
	//{
	//	char input;
	//	scanf(" %c", &input); //공백을 두어 디버깅한다.?
	//	char result = ToSwapCharacter(input);
	//	printf("결과 : %c\n", result);
	//}

	//void* a; //포인터는 주소라 모두 4바이트 고로 void*는 저장 가능
	//Void 함수란?
	WhatIsVoid();
	
	//전방선언이란?
	printf("%s\n", WhatIsPrototype().c_str()); //리턴값이 찍힌다. 함수가 죽으면서 리턴을 남기고 죽는다.

	//오버로딩이란? -> 파라미터로 구별
	// ->1) 파라미터의 타입이 달라야함
	WhatIsOverloading(); //한번 조사해보기 call by value, address, reference
	WhatIsOverloading(30);
	WhatIsOverloading(30.0f);
	WhatIsOverloading(10, 20);

	//템플릿 함수란?
	WhatIsTemplate(9); //T가 파라미터 타입을 보고 판단하고 그걸로 바뀐다 이건 int로 바뀜
	WhatIsTemplate(99.9f);
	WhatIsTemplate('Z');
	WhatIsTemplate(new int);

	//auto a = "a"; // void처럼 선언만 하면 빨간줄이 그인다 정확한 데이터 타입의 크기를 알수 없다. //데이터 타입이 뭔지 모를때 그냥 알아서 찾아준다.

	system("pause");
	return 0;
}

string WhatIsPrototype()
{
	printf("나는 메인함수보다 후위에 선언되어 있습니다.\n");
	return "집에 가고 싶다"; //리턴 조사;;
}

void WhatIsPrototype2()
{
	printf("냉무\n");
}

void WhatIsOverloading()
{
	printf("나는 파람이 없다\n");
}

void WhatIsOverloading(int a)
{
	printf("나는 1파람이다. : %d\n", a);
}

void WhatIsOverloading(int a, int b)
{
	printf("나는 2파람이다. : %d, %d\n", a, b);
}

void WhatIsOverloading(float a)
{
	printf("(float)나는 1파람이다. : %f\n", a);
}

