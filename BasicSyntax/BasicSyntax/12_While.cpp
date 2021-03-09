#include <stdio.h>
#include <Windows.h>

int main()
{/*
	bool isContinue = true;

	while (isContinue)
	{
		system("cls");
		printf("슉=\n");
		Sleep(200);

		system("cls");
		printf("=샥\n");
		Sleep(200);

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
		{
			printf("꽥\n");
			isContinue = false;
		}
}*/

	/*int iter = 0;
	int sum = 0;
	while (iter <= 5)
	{
		sum += iter;
		printf("%d 번째 반복 중\n", iter);
		iter++;
	}
	printf("합계 : %d\n", sum);*/

	//int playerHP = 10;
	//int playerATK = 2;
	//int monsterHP = 5;
	//int monsterATK = 1;

	//printf("전투시작!\n");
	//while (playerHP > 0 && monsterHP > 0)
	//{
	//	monsterHP -= playerATK;
	//	playerHP -= monsterATK;
	//	printf("몬스터 체력 : %d VS %d : 플레이어 체력\n", monsterHP, playerHP);
	//	Sleep(1000); //1초 기다려줌
	//}

	//do~while 문은 평가값에 상관없이 무조건 1회 실행 -> 조건이 참인 경우 반복 실행
	int myVersion = 1;
	do
	{
		printf("당신의 버전은 %d 입니다.\n", myVersion);
		myVersion++;
		printf("현재 당신의 버전은 %d 입니다.\n", myVersion);

	} while (myVersion != 2);

	system("pause");
	return 0;
}