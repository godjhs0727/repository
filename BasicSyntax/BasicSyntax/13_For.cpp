#include <stdio.h>
#include <Windows.h>

int main()
{
	//int i;

	////for (i = 0; i < 5; i++) //������ġ; �򰡰�;������ �ĸ� ��� �������� �ϳ� �� �Ѽ� �ִ�.
	////	printf("i�� ���� ���� : %d\n", i);//���ٸ� �������� �߰�ȣ ��������

	//int input;
	//printf("�� �� ������ �ͳ���?");
	//scanf("%d", &input);

	//for (i = 0; i < input; i++)
	//	printf("��! ");

	//printf("\n");

	//int i = 5;
	//for (i; i > 0; i--)
	//	printf("%d\n", i);

	//for (;;)//���� �ݺ���
	//{
	//	printf("���� ���� �ݺ�\n");

	//	if (GetAsyncKeyState(VK_LSHIFT)) //���� ����ƮŰ ������ �극��ũ
	//		break;
	//}

	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	if (i == 4) //continue 4�� ������ 4�� �����ϰ� 5�� �Ѿ�� �ٽ� �����Ѵ�.
	//		continue;

	//	printf("%d\n", i);
	//}

	////Local Variable ��������
	//printf("ù��° for��\n");
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%d\n", i);
	//}	

	//printf("�ι�° for��\n");
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d\n", i);
	//}

	//{
	//	int a;
	//	printf("%x\n", &a); //&a �ּ� ���� ���
	//}
	//{
	//	int a;
	//	printf("%x\n", &a); //%d�� 10���� %x�� 16���� %o�� 8����
	//}
	////
	////{
	////	int a;
	////	a = 100; //a�� Ȱ�뼺�� ��ȣ ���������� �� �̻� ���� �Ұ�
	////}

	//���� for��
	/*for (int i = 0; i < 3; i++)
	{
		printf("��");
		for (int j = 0; j < 2; j++)
		{
			printf("��");
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

	//�� ���1
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

	//������
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 2; j <= 9; j++)
		{
			printf("%d * %d = %d\t", j, i, j*i);
		}
		printf("\n");
	}

	//���� 3�� for�� ������
	
	
	system("pause");
	return 0;
}