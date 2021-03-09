#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string>

int main()
{
	///방법 #1
#pragma region Solution1
	//int player, com;

	//srand((UINT)time(NULL));

	//while (true)
	//{
	//	com = rand() % 3; //컴퓨터의 가위바위보

	//	printf("----------\n");
	//	printf("\n입력 : ");
	//	scanf("%d", &player);

	//	//0 : 가위 , 1 : 바위, 2 : 보

	//	//누가 뭘 냈는지, 숫자로 표시
	//	printf("Player : %d VS %d : Com\n", player, com);

	//	//플레이어가 가위를 낸 경우
	//	if (player == 0)
	//	{
	//		if (com == 0) //컴퓨터 가위를 낸 경우
	//		{
	//			printf("비김\n");
	//		}
	//		else if (com == 1) //컴퓨터가 바위를 낸 경우
	//		{
	//			printf("짐\n");
	//		}
	//		else //컴퓨터가 보를 낸 경우
	//		{
	//			printf("이김\n");
	//		}
	//	}//플레이어 : 가위

	//	//플레이어가 바위를 낸 경우
	//	else if (player == 1)
	//	{
	//		if (com == 0) //컴퓨터 가위를 낸 경우
	//		{
	//			printf("이김\n");
	//		}
	//		else if (com == 1)  //컴퓨터가 바위를 낸 경우
	//		{
	//			printf("비김\n"); 
	//		}
	//		else //컴퓨터가 보를 낸 경우
	//		{
	//			printf("짐\n");
	//		}
	//	}//플레이어 : 바위

	//	//플레이어가 보를 낸 경우
	//	else if (player == 2)
	//	{
	//		if (com == 0) //컴퓨터 가위를 낸 경우
	//		{
	//			printf("짐\n");
	//		}
	//		else if (com == 1)  //컴퓨터가 바위를 낸 경우
	//		{
	//			printf("이김\n");
	//		}
	//		else //컴퓨터가 보를 낸 경우
	//		{
	//			printf("비김\n");
	//		}
	//	}//플레이어 : 보

	//} //while(true)
#pragma endregion

	///방법 #2
	int player, com;
	int playerWin = 0, comWin = 0;
	bool bContinue = true;

	std::string str;

	srand((UINT)time(NULL));


	while(bContinue)
	{
		system("cls");
		printf("플레이어 승 : %d,  컴퓨터 승 : %d\n", playerWin, comWin);

		if (comWin >= 3 || playerWin >= 3)
		{
			printf("최종 승자 : ");
			if (playerWin >= 3)
				printf("플레이어");
			else
				printf("컴퓨터");
			printf("\n");
			
			//반복문 탈출 방법 1 : 직접 반복문에 들어가는 조건 변수를 수정하는 방법
			//bContinue = false;

			//반복문 탈출 방법 : break(즉시 탈출 됨)
			break;
		}

		com = rand() % 3;

		printf("-----------\n");
		printf("\n입력 : ");
		scanf("%d", &player);

		if (player == 0) 
			str = "가위";
		else if (player == 1) 
			str = "바위";
		else if  (player == 2) 
			str = "보";
		printf("Player : %s VS ", str.c_str());

		if (com == 0)
			str = "가위";
		else if (com == 1)
			str = "바위";
		else if (com == 2)
			str = "보";
		printf("%s : Com\n", str.c_str());
		

		if (player == com)
			printf(" -> 비김\n");
		else if (player == (com + 1) % 3)
		{
			printf(" -> 이김\n");
			playerWin++; //playerWin = playerWin + 1;
		}
		else
		{
			printf(" -> 짐\n");
			comWin++;
		}

		system("pause");
	}

	system("pause");
	return 0;

	// && : 두 항이 둘 다 참일때만 참
	// || : 두 항 중 둘 중 하나라도 참이면 참
	//(1 < 10) && (1 > 8); //-> false(AND);
	//(1 < 10) || (1 > 8); //-> true;(OR)

}