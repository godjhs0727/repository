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
	//printf("���� ����(0~2) (ġƮ : %d) : ", random);
	//scanf("%d", &input);

	//if (input < 0 || input > 2)
	//	printf("�ȹٷ� �Է��ؾ��մϴ�\n");
	//else
	//{
	//	if (cup[input] == 0)
	//		printf("Ʋ��\n");
	//	else
	//		printf("õ������ ���� �����ϴ�.\n");
	//}
	//



	//for (int i = 0; i < 3; i++)
	//	printf("cup[%d] �� ��� �ִ� ���� %d ���̴�.\n", i, cup[i]);

	//int a = 3;
	//int b = 5;
	//int c;

	//printf("���� �� -- a : %d, b : %d\n", a, b);

	////������ �ӽ� ���ǼҰ� �ʿ��ϴ� c�� �ӽ� ���Ǽ�
	//c = a;
	//a = b;
	//b = c;

	//printf("���� �� -- a : %d, b : %d\n", a, b);

	int arr[5] = { 10, 54, 19, 23, 7 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1; j++)
		{
			if(arr[j]>arr[j+1]) //�������� ASC : >, �������� DSC : < // �������� ���������� ������ ��ȣ�� �ݴ�� ������ �ȴ�. ����� ��������
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
		}
	}

	//���
	for (int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[1]);

	//����
	int arrSorted[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("���� �� : ");
	for (int i = 0; i < 10; i++)
		printf("%d, ", arrSorted[i]);
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % 10;
		int r2 = rand() % 10;
		
		//������
		int temp = arrSorted[r1];
		arrSorted[r1] = arrSorted[r2];
		arrSorted[r2] = temp;
	}

	printf("���� �� : ");
	for (int i = 0; i < 10; i++)
		printf("%d, ", arrSorted[i]);
	printf("\n");

	//2���� �迭
	int d2Arr[2][3];//���� ������ �ڰ� ������ //������ [0]�� ������ [0][1][2] ���ְ� ������ [1]�� ������ [0][1][2] ���ְ� 3���� 4���� �� �Ȱ��� ���
	
	//�ʱ�ȭ 1 ���Һ� �ʱ�ȭ
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

	//1�� for��(������...)
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