#include <stdio.h>
#include <Windows.h>

int main()
{

	//if ����
	int input = 1;
	
	while (true)
	{
		printf("���ڸ� �ϳ� �Է��ϼ��� : ");
		scanf("%d", &input);

		/*if (input == 7)
		{
			printf("���� 7�̴�.\n");
		}
		else if(input > 0)
		{
			printf("���� 7�� �ƴϸ鼭, ������̴�.\n");
		}
		else if (input < 0)
		{
			printf("���� 7�� �ƴϸ鼭, �������̴�.\n");
		}
		else
		{
			printf("���� 7�� �ƴϴ�\n");
		}*/

		//���� ������ �����Ҷ� ���ǻ���
		/*if (input > 0)
		{
			printf("+\n");
		}
		else if (input == 7)
		{
			printf("7\n");
		}*/

		if (input > 0)
		{
			if (input == 1)
			{
				printf("1�� �Էµ�\n");
			}
			else if (input == 2)
			{
				printf("2�� �Էµ�\n");
			}
			else
			{
				printf("1�� 2�� �ƴ� ������� �Էµ�");
			}

		} //if(input > 0)
		else
		{
			printf("����� �ƴ� ���� �Էµ�\n");
		}

		
	} //while
	

	system("pause");
	return 0;
}