#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string>

int main()
{
	///��� #1
#pragma region Solution1
	//int player, com;

	//srand((UINT)time(NULL));

	//while (true)
	//{
	//	com = rand() % 3; //��ǻ���� ����������

	//	printf("----------\n");
	//	printf("\n�Է� : ");
	//	scanf("%d", &player);

	//	//0 : ���� , 1 : ����, 2 : ��

	//	//���� �� �´���, ���ڷ� ǥ��
	//	printf("Player : %d VS %d : Com\n", player, com);

	//	//�÷��̾ ������ �� ���
	//	if (player == 0)
	//	{
	//		if (com == 0) //��ǻ�� ������ �� ���
	//		{
	//			printf("���\n");
	//		}
	//		else if (com == 1) //��ǻ�Ͱ� ������ �� ���
	//		{
	//			printf("��\n");
	//		}
	//		else //��ǻ�Ͱ� ���� �� ���
	//		{
	//			printf("�̱�\n");
	//		}
	//	}//�÷��̾� : ����

	//	//�÷��̾ ������ �� ���
	//	else if (player == 1)
	//	{
	//		if (com == 0) //��ǻ�� ������ �� ���
	//		{
	//			printf("�̱�\n");
	//		}
	//		else if (com == 1)  //��ǻ�Ͱ� ������ �� ���
	//		{
	//			printf("���\n"); 
	//		}
	//		else //��ǻ�Ͱ� ���� �� ���
	//		{
	//			printf("��\n");
	//		}
	//	}//�÷��̾� : ����

	//	//�÷��̾ ���� �� ���
	//	else if (player == 2)
	//	{
	//		if (com == 0) //��ǻ�� ������ �� ���
	//		{
	//			printf("��\n");
	//		}
	//		else if (com == 1)  //��ǻ�Ͱ� ������ �� ���
	//		{
	//			printf("�̱�\n");
	//		}
	//		else //��ǻ�Ͱ� ���� �� ���
	//		{
	//			printf("���\n");
	//		}
	//	}//�÷��̾� : ��

	//} //while(true)
#pragma endregion

	///��� #2
	int player, com;
	int playerWin = 0, comWin = 0;
	bool bContinue = true;

	std::string str;

	srand((UINT)time(NULL));


	while(bContinue)
	{
		system("cls");
		printf("�÷��̾� �� : %d,  ��ǻ�� �� : %d\n", playerWin, comWin);

		if (comWin >= 3 || playerWin >= 3)
		{
			printf("���� ���� : ");
			if (playerWin >= 3)
				printf("�÷��̾�");
			else
				printf("��ǻ��");
			printf("\n");
			
			//�ݺ��� Ż�� ��� 1 : ���� �ݺ����� ���� ���� ������ �����ϴ� ���
			//bContinue = false;

			//�ݺ��� Ż�� ��� : break(��� Ż�� ��)
			break;
		}

		com = rand() % 3;

		printf("-----------\n");
		printf("\n�Է� : ");
		scanf("%d", &player);

		if (player == 0) 
			str = "����";
		else if (player == 1) 
			str = "����";
		else if  (player == 2) 
			str = "��";
		printf("Player : %s VS ", str.c_str());

		if (com == 0)
			str = "����";
		else if (com == 1)
			str = "����";
		else if (com == 2)
			str = "��";
		printf("%s : Com\n", str.c_str());
		

		if (player == com)
			printf(" -> ���\n");
		else if (player == (com + 1) % 3)
		{
			printf(" -> �̱�\n");
			playerWin++; //playerWin = playerWin + 1;
		}
		else
		{
			printf(" -> ��\n");
			comWin++;
		}

		system("pause");
	}

	system("pause");
	return 0;

	// && : �� ���� �� �� ���϶��� ��
	// || : �� �� �� �� �� �ϳ��� ���̸� ��
	//(1 < 10) && (1 > 8); //-> false(AND);
	//(1 < 10) || (1 > 8); //-> true;(OR)

}