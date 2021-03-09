#include <stdio.h>
#include <Windows.h>
#include <time.h>

int main()
{
	int  com[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int player[3];

	int strike = 0;
	int ball = 0;
	int input;
	srand((UINT)time(NULL));

	//����
	for (int i = 0; i < 100; i++)
	{
		int r1 = rand() % 10;
		int r2 = rand() % 10;
	
		int temp = com[r1];
		com[r1] = com[r2];
		com[r2] = temp;
	}

	//������
	while (true)
	{
		system("cls");

		//ġƮ
		printf("ġƮ : %d%d%d\n", com[0], com[1], com[2]);
		printf("-----<������>---\n");
		printf("\n\n\n");
		printf("----------------\n");
		//�Է�
		printf("���ڸ� �� �Է� : ");
		scanf("%d", &input);

		//�ڸ��� ������
		player[0] = input / 100;
		player[1] = input / 10 % 10;
		player[2] = input % 10;

		//printf("100�� �ڸ��� : ");
		//scanf("%d", &player[0]);

		//printf("10�� �ڸ��� : ");
		//scanf("%d", &player[1]);

		//printf("1�� �ڸ��� : ");
		//scanf("%d", &player[2]);

		//�ڸ��� ��
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (player[i] == com[j])
				{
					if (i == j) strike++;
					else ball++;
				}
			}
		}
		/*if (player[0] == com[0]) strike++;
		else if (player[0] == com[1]) ball++;
		else if (player[0] == com[2]) ball++;

		if (player[1] == com[1]) strike++;
		else if (player[1] == com[0]) ball++;
		else if (player[1] == com[2]) ball++;

		if (player[2] == com[2]) strike++;
		else if (player[2] == com[1]) ball++;
		else if (player[2] == com[0]) ball++;*/

		//���
		COORD curPosition;
		curPosition.X = 0;
		curPosition.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curPosition);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
		//RGB : ���� �����
		//CMY : ���� �����
		printf("Strike : %d\n", strike);
		printf("Ball : %d\n", ball);
		printf("Out : %d\n", 3 - strike - ball);
		printf("---------------------\n");
		Sleep(1000); //1�� ����

		//���� ��
		if (strike >= 3)
			break;

		strike = ball = 0;
	}

	system("pause");
	return 0;
}