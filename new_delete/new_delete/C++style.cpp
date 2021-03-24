/*
c++에서 c언어의 표준함수 호출하기
c를 더하고 .h를 빼라
c++에서는 함수 오버로딩이 가능하기 때문에 자료형에 따라서 함수의 이름을 달리해서 정의하지 않고,
보다 사용하기 편하도록 함수를 오버로딩 해 놓은 것이다. 이렇듯 c++문번을 기반으로 개선된 형태로
라이브러리가 구성되어 있으므로, 가급적 c++의 표준헤더를 이용해서 함수를 호출하는 것이 좋다.
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

int main()
{
	char str1[] = "Result"; //string 헤더 적용
	char str2[30];

	strcpy(str2, str1); //str2도 "Result"가 저장된다.
	printf("%s: %f \n", str1, sin(0.14)/*math헤더 적용(sin삼각함수)*/);
	printf("%s: %f \n", str2, abs(-1.25)/*abs는 절대값*/);

	return 0;
}