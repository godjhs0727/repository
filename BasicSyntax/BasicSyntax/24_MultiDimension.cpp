#include "stdafx.h"

void InitArray(int* begin,int size);
void PrintArray(int*begin, int size);
void SetValue(int** ptr);

int main()
{
	////배열의 이름이 시작주소를 가리키는 포인터
	////2차원 배열
	//int d1Arr[] = { 1,2,3 }; //중괄호 초기화 하면 앞에 안쓸수 있다.
	//int d2Arr[][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } }; //00,01,02,03 ,10,11,12,13, 20,21,22,23

	//cout << " [0] 주소" << d2Arr[0] << endl; //d2Arr[0][0]~[3]의 시작 주소 4*4 16 그래서 아래랑 16차이 16진수 배열의 전체 시작주소
	//cout << " [1] 주소" << d2Arr[1] << endl;//고차원 1번에 대한 시작 주소
	//cout << "[1][0] 주소 " << &d2Arr[1][0] << endl; //두번째와 같음

	////배열을 파라미터로 넘기는 예
	//int capacity;
	//cout << "배열의 크기를 지정해주세요 : ";
	//cin >> capacity;
	//
	//int*arr = new int[capacity]; //뉴 할당 해서 힙 영역 뚫음

	//InitArray(arr, capacity);
	//PrintArray(arr, capacity);

	//cout << "---------------------\n";
	//int normalArr[5] = { 100,200,300,400,500 };
	//PrintArray(normalArr, 5);
	//int* param = arr;
	//int* ptr;
	//int a = 100;
	//ptr = &a;

	//SetValue(ptr); //Call By Address

	//cout << a << endl; //a 의 주소값

	//더블 포인터
	int* a = NULL;
	SetValue(&a);
	cout << *a << endl;

	//double b = 2;
	//double* ptr = &b; //포인터의 주소를 저장하는 타입은 더블포인터이다.
	//double** ptr2 = &ptr; //더블포인터도 스택변수라서 본인 주소가 또 있다.

	//cout << ptr2 << endl; //ptr2의 값, ptr의 주소
	//cout << *ptr2 << endl; //ptr의 값, b의 주소
	//cout << **ptr2 << endl; // b의 값

	//void*
	//int arr[3] = { 1,2,3 };
	//cout << *(arr + 2) << endl; //2번 인덱스의 시작주소
	double number = 2020; //가져오는게 8 바이트라서 쓸데없는것까지 가져오기 때문에 pPtr = int &number 가 불가능함
	void* vPtr = &number; //void는 아무거나 다 받을수 있다.
	cout << *(double*)vPtr << endl; //void는 명시되어있지 않기때문에 데이터 타입을 앞에 써주어야함

	system("pause");
	return 0;
}

void InitArray(int * begin, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(begin + i) = i; //포인터도 배열이 가능하다. b[i] == *(b + 1)
	}
}

void PrintArray(int * begin, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << begin[i] << endl; //인덱스만큼 건너뛰는 연산자이다.
	}
}

void SetValue(int ** ptr)
{
	*ptr = new int;
	**ptr = 999;
}
