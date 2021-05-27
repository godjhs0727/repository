/*
문제1
다음 표준함수를 호출하는 예제를 만들되, c++의 헤더를 선언해서 만들어보자. 그리고 예제의 내용은
상관없지만, 아래의 함수들을 최소 1회 이상 호출해야 한다. 참고로 다음 함수들은 C언어의 경우
<string.h>에 선언되어 있다.
-strlen 문자열의 길이 계산
-strcat 문자열의 뒤에 덧붙이기
-strcpy 문자열 복사
-strcmp 문자열 비교

문제2
다음 세 함수를 이용해서 0이상 100미만의 난수를 총 5개 생성하는 예제를 만들되, c++의 헤더를
선언해서 작성해보자, 참고로 c언어의 경우 time 함수는 <time.h>에 선언되어 있고, rand함수와
srand함수는 <stdlib.h>에 선언되어 있다.
rand, srand, time
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//문제1
	const char *str1 = "ABC 123 ";
	const char *str2 = "DEF 456 ";
	char str3[50];
	cout << strlen(str1) << endl; //문자길이 띄어쓰기까지 포함하여 8
	cout << strlen(str2) << endl;
	strcpy(str3, str1); //복사를 했다 이젠 str3도 같다
	strcat(str3, str2); //str3 뒤에 str2를 붙인다.
	cout << str3 << endl;

	if (strcmp(str1, str2) == 0) //둘이 문자열이 완전히 같은가 비교 (글자 하나하나)
		cout << "문자열이 같다." << endl;
	else
		cout << "문자열이 같지 않다." << endl;

	//문제2
	srand(time(NULL)); //time함수로 난수를 만들수 있다
	for (int i = 0; i < 5; i++)
	{
		printf("Random number #%d: %d\n", i, rand() % 100/*0이상 100미만의 난수를 만들기에 mod함수의 나머지 0~99숫자가 나오기에 rand() % 100*/);
	}

	return 0;
}