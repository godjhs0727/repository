#include <stdio.h>
#include <Windows.h>

int main()
{
	int arr[10];  //T name[size] : �迭 ���� ���

	//�ʱ�ȭ ��� 1 (���� ���� �ʱ�ȭ) �ε��� ��ȣ�� ������ �����̾���Ѵ�. unsigned int
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	arr[5] = 6;
	arr[6] = 7;
	arr[7] = 8;
	arr[8] = 9;
	arr[9] = 10;

	printf("%d\n", arr[6]);

	printf("------------------------\n");

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);

	//�ʱ�ȭ ��� 2 (�߰�ȣ �ʱ��) - �׻� ���� �ٿ� ��� �Ѵ�.
	int arr2[5] = { 10, 20, 30, 40, 50 };


	printf("===\n");
	for (int i = 0; i < 5; i++)
		printf("%d\n", arr2[i]);


	system("pause");
	return 0;
}