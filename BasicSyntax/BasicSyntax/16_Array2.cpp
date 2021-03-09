#include <stdio.h>
#include <Windows.h>
#include<time.h>


int main()
{
	//srand((UINT)time(0));

	//int cup[3];
	//int random = rand() % 3;
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	if (i == random)
	//		cup[i] = 10000000;
	//	else
	//		cup[i] = 0;
	//}
	//
	//int input;
	//printf("컵을 골라라(0~2) (치트 : %d) : ", random);
	//scanf("%d", &input);

	//if (input < 0 || input > 2)
	//	printf("똑바로 입력해야합니다\n");
	//else
	//{
	//	if (cup[input] == 0)
	//		printf("틀림\n");
	//	else
	//		printf("천만원은 이제 제껍니다.\n");
	//}
	//



	//for (int i = 0; i < 3; i++)
	//	printf("cup[%d] 에 들어 있는 돈은 %d 원이다.\n", i, cup[i]);

	//int a = 3;
	//int b = 5;
	//int c;

	//printf("스왑 전 -- a : %d, b : %d\n", a, b);

	////스와핑 임시 대피소가 필요하다 c가 임시 대피소
	//c = a;
	//a = b;
	//b = c;

	//printf("스왑 후 -- a : %d, b : %d\n", a, b);

	int arr[5] = { 10, 54, 19, 23, 7 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1; j++)
		{
			if(arr[j]>arr[j+1]) //오름차순 ASC : >, 내림차순 DSC : < // 오름차순 내림차순의 기준은 부호만 반대로 돌리면 된다. 현재는 오름차순
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
		}
	}

	//출력
	for (int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[1]);

	//셔플
	int arrSorted[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("셔플 전 : ");
	for (int i = 0; i < 10; i++)
		printf("%d, ", arrSorted[i]);
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % 10;
		int r2 = rand() % 10;
		
		//스와핑
		int temp = arrSorted[r1];
		arrSorted[r1] = arrSorted[r2];
		arrSorted[r2] = temp;
	}

	printf("셔플 후 : ");
	for (int i = 0; i < 10; i++)
		printf("%d, ", arrSorted[i]);
	printf("\n");

	//2차원 배열
	int d2Arr[2][3];//앞이 고차원 뒤가 저차원 //고차원 [0]에 저차원 [0][1][2] 들어가있고 고차원 [1]에 저차원 [0][1][2] 들어가있고 3차원 4차원 다 똑같은 방식
	
	//초기화 1 원소별 초기화
	d2Arr[0][0] = 1;
	d2Arr[0][1] = 2;
	d2Arr[0][2] = 3;

	d2Arr[1][0] = 4;
	d2Arr[1][1] = 5;
	d2Arr[1][2] = 6;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\n", d2Arr[i][j]);
		}
	}

	//1중 for문(억지로...)
	for (int i = 0; i < 6; i++)
		printf("%d\n", d2Arr[i / 3][i % 3]);
	// -> i = 0 [0][0] = 1;
	// -> i = 1 [0][1] = 2;
	// -> i = 2 [0][2] = 3;
	// -> i = 3 [1][0] = 4;
	// -> i = 4	[1][1] = 5;
	// -> i = 5	[1][2] = 6;

	system("pause");
	return 0;
}