#include "stdafx.h"
// ./는 상대 경로../../할때마다 상위폴더
void Swap(int a, int b);
void Swap(int* a, int* b);
void SwapReference(int& a, int& b);

double globalVar = 77; //전역변수보다는 Call By Address 쪽으로 사용하는걸 추천

void SetGlobal(double val);

int main()
{
	int a = 10, b = 1;

	//Call By Value
	cout << "스왑 전 : " << a << ", " << b << endl;
	Swap(a, b);
	cout << "스왑 후 : " << a << ", " << b << endl;

	//Call By Address
	cout << "스왑 전 : " << a << ", " << b << endl;
	Swap(&a, &b);
	cout << "스왑 후 : " << a << ", " << b << endl;

	//Reference
	int& ref = a;
	cout << &a << endl;
	cout << &ref << endl;

	//Call By Reference  Adress처럼 원본값 바꿀수도 있고 메모리 공간도 절약이 가능함.
	cout << "스왑 전 : " << a << ", " << b << endl;
	SwapReference(a, b);
	cout << "스왑 후 : " << a << ", " << b << endl;

	cout << "전역 변수 : " << globalVar << endl;
	SetGlobal(99);
	cout << "전역 변수 : " << globalVar << endl;

	//상수
	const float PI = 3.141592f; //수정이 되면 안되는 변수를 const
	// 예제 ; PI = 10.0f;
	//static
	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		int count = 1;
		num = count++;
	}
	cout << "일반 변수 : " << num << endl;

	for (int i = 0; i < 3; i++)
	{
		static int count = 1; //스태틱 변수는 한번만 사용하고 계속 누적 된다. 선언이 또 되면 무시된다.
		num = count++;
	}
	cout << "스태틱 변수 : " << num << endl;

	system("pause");
	return 0;
}

void Swap(int a, int b)
{
	int c = a;
	a = b;
	b = c;

}

void Swap(int * a, int * b) //각복사가 발생하고 메모리 공간 할당이 필요하고 주소값을 바꾸고
{
	int c = *a;
	*a = *b;
	*b = c;
}

void SwapReference(int & a, int & b) //각복사 필요 없고 메모리 공간 할당도 필요없고 주소값도 따로 바꿀필요없기 때문에 효율이 좋다.
{
	int c = a;
	a = b;
	b = c;
}

void SetGlobal(double val)
{
	globalVar = val;
}
