#include <stdio.h>
#include <Windows.h>

int main()
{/*
	bool isContinue = true;

	while (isContinue)
	{
		system("cls");
		printf("��=\n");
		Sleep(200);

		system("cls");
		printf("=��\n");
		Sleep(200);

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
		{
			printf("��\n");
			isContinue = false;
		}
}*/

	/*int iter = 0;
	int sum = 0;
	while (iter <= 5)
	{
		sum += iter;
		printf("%d ��° �ݺ� ��\n", iter);
		iter++;
	}
	printf("�հ� : %d\n", sum);*/

	//int playerHP = 10;
	//int playerATK = 2;
	//int monsterHP = 5;
	//int monsterATK = 1;

	//printf("��������!\n");
	//while (playerHP > 0 && monsterHP > 0)
	//{
	//	monsterHP -= playerATK;
	//	playerHP -= monsterATK;
	//	printf("���� ü�� : %d VS %d : �÷��̾� ü��\n", monsterHP, playerHP);
	//	Sleep(1000); //1�� ��ٷ���
	//}

	//do~while ���� �򰡰��� ������� ������ 1ȸ ���� -> ������ ���� ��� �ݺ� ����
	int myVersion = 1;
	do
	{
		printf("����� ������ %d �Դϴ�.\n", myVersion);
		myVersion++;
		printf("���� ����� ������ %d �Դϴ�.\n", myVersion);

	} while (myVersion != 2);

	system("pause");
	return 0;
}