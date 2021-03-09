#include <stdio.h>
#include <Windows.h>

int main()
{
	int arr[10];  //T name[size] : 배열 선언 방법

	//초기화 방법 1 (원소 개별 초기화) 인덱스 번호는 무조건 정수이어야한다. unsigned int
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	arr[5] = 6;
	arr[6] = 7;
	arr[7] = 8;
	arr[8] = 9;
	arr[9] = 10;

	printf("%d\n", arr[6]);

	printf("------------------------\n");

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);

	//초기화 방법 2 (중괄호 초기법) - 항상 같은 줄에 써야 한다.
	int arr2[5] = { 10, 20, 30, 40, 50 };


	printf("===\n");
	for (int i = 0; i < 5; i++)
		printf("%d\n", arr2[i]);


	system("pause");
	return 0;
}