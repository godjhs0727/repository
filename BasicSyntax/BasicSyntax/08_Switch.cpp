#include <stdio.h>
#include <Windows.h>

int main()
{
	int money = 1000;
	int swordCost = 100, gunCost = 200, spearCost = 300;

	int input;

	while (true)
	{
		printf("(1)Į (2)�� (3)â\n");
		printf("-------------------\n");
		printf("�� �췡? : ");
		scanf("%d", &input);

		//switch~case
		switch (input)
		{
			case 1 : 
			{
				money -= swordCost; //money = money - swordCost
				printf("Į�� %d���� ��� -> ���� �� %d\n", swordCost, money);
			}
			//break;

			case 2:
			{
				money -= gunCost; //money = money - swordCost
				printf("���� %d���� ��� -> ���� �� %d\n", gunCost, money);
			}
			break;

			case 3:
			{
				money -= spearCost; //money = money - swordCost
				printf("â�� %d���� ��� -> ���� �� %d\n", spearCost, money);
			}
			break;

			default :
			{
				printf("������ ���� ���� ���õ�\n");
			}
		}

		printf("\n");

	}//while


	system("pause");
	return 0;
}