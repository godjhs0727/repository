#include <iostream>
#include <string.h>//c언어 헤더파일 추가
#include <stdlib.h>//위와 동
using namespace std;

char *MakeStrAdr(int len)
{
	//char *str = (char*)malloc(sizeof(char)*len); //문자열 저장을 위한 배열을 힙 영역에 할당
	char*str = new char[len];
	return str;
}

int main()
{
	char*str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	//free(str); //힙에 할당된 메모리 공간을 소멸
	delete[]str;
	return 0;
}
/* 불편사항이 있다.
할당할 대상의 정보를 무조건 바이트 크기단위로 전달해야 한다.
반환형이 void형 포인터이기 때문에 적절한 형 변환을 거쳐야 한다.
*/
/*
c++에서 제공하는 new와 delete를 사용하면 간편하다.
int형 변수의 할당				int* ptr1 = new int;
double 형 변수 할당				double* ptr2 = new double;
길이가 3인 int형 배열의 할당	int* arr1 = new int[3];
길이가 7인 double 형 배열 할당	double* arr2 = new double[7];

앞서 할당한 변수, 배열 소멸
								delete ptr1;
								delete ptr2;
								delete []arr1;
								delete []arr2;
*/