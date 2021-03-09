#include <stdio.h>
#include <Windows.h>

int main()
{
	int money = 1000;
	int swordCost = 100, gunCost = 200, spearCost = 300;

	int input;

	while (true)
	{
		printf("(1)Ä® (2)ÃÑ (3)Ã¢\n");
		printf("-------------------\n");
		printf("¹» »ì·¡? : ");
		scanf("%d", &input);

		//switch~case
		switch (input)
		{
			case 1 : 
			{
				money -= swordCost; //money = money - swordCost
				printf("Ä®À» %d¿ø¿¡ »ò´Ù -> ³²Àº µ· %d\n", swordCost, money);
			}
			//break;

			case 2:
			{
				money -= gunCost; //money = money - swordCost
				printf("ÃÑÀ» %d¿ø¿¡ »ò´Ù -> ³²Àº µ· %d\n", gunCost, money);
			}
			break;

			case 3:
			{
				money -= spearCost; //money = money - swordCost
				printf("Ã¢À» %d¿ø¿¡ »ò´Ù -> ³²Àº µ· %d\n", spearCost, money);
			}
			break;

			default :
			{
				printf("¹üÀ§¿¡ ¾ø´Â °ªÀ» ¼±ÅÃµÊ\n");
			}
		}

		printf("\n");

	}//while


	system("pause");
	return 0;
}