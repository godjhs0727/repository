#include <stdio.h>
#include <Windows.h>

int main()
{
	//int i;

	////for (i = 0; i < 5; i++) //시작위치; 평가값;증감자 컴마 찍고 증감값을 하나 더 둘수 있다.
	////	printf("i의 현재 값은 : %d\n", i);//한줄만 있을때는 중괄호 생략가능

	//int input;
	//printf("몇 대 때리고 싶나요?");
	//scanf("%d", &input);

	//for (i = 0; i < input; i++)
	//	printf("퍽! ");

	//printf("\n");

	//int i = 5;
	//for (i; i > 0; i--)
	//	printf("%d\n", i);

	//for (;;)//무한 반복문
	//{
	//	printf("나는 무한 반복\n");

	//	if (GetAsyncKeyState(VK_LSHIFT)) //왼쪽 쉬프트키 누르면 브레이크
	//		break;
	//}

	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	if (i == 4) //continue 4를 만나면 4를 배제하고 5로 넘어가서 다시 시작한다.
	//		continue;

	//	printf("%d\n", i);
	//}

	////Local Variable 지역변수
	//printf("첫번째 for문\n");
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%d\n", i);
	//}	

	//printf("두번째 for문\n");
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d\n", i);
	//}

	//{
	//	int a;
	//	printf("%x\n", &a); //&a 주소 보는 방법
	//}
	//{
	//	int a;
	//	printf("%x\n", &a); //%d는 10진수 %x는 16진수 %o는 8진수
	//}
	////
	////{
	////	int a;
	////	a = 100; //a의 활용성은 괄호 끝날때까지 그 이상 접근 불가
	////}

	//이중 for문
	/*for (int i = 0; i < 3; i++)
	{
		printf("으");
		for (int j = 0; j < 2; j++)
		{
			printf("아");
		}
		printf("\n");
	}*/

	//for (int hour = 0; hour <= 12; hour++)
	//{
	//	for (int min = 0; min < 60; min++)
	//	{
	//		printf("%d : %d\n", hour, min);
	//	}
	//}

	//별 찍기1
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//구구단
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 2; j <= 9; j++)
		{
			printf("%d * %d = %d\t", j, i, j*i);
		}
		printf("\n");
	}

	//과제 3중 for문 구구단
	
	
	system("pause");
	return 0;
}