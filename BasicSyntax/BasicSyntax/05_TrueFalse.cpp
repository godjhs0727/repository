#include <stdio.h>
#include <Windows.h>

int main()
{
	//���迬�� -> ����� ��(1, true) Ȥ�� ����(0, false)
	//int a = 100;
	//int b = 20;

	//printf("a > b = %d\n", a > b); //ũ�� -> 1
	//printf("a < b = %d\n", a < b); //�۴� -> 0
	//printf("a == b = %d\n", a == b); //���� -> 0
	//printf("a == b = %d\n", a != b); //���� �ʴ� -> 0
	//printf("a >= b = %d\n", a >= b); //ũ�ų� ���� -> 1
	//printf("a <= b = %d\n", a <= b); //�۰ų� ���� -> 0

	//���� ������
	/*int input1, input2;

	printf("1st : ");
	scanf("%d", &input1);

	printf("2nd : ");
	scanf("%d", &input2);

	int max = (input1 > input2) ? (input1) : (input2);
	printf("�� �� ū ���� : %d �̴�.\n", max);*/

	//bool
	bool bAlive = true;
	printf("(1)���뽺���� �׿��ִ� ��, (2)ȫ����\n");
	printf("� ���� ������ ? :");

	int select;
	scanf("%d", &select);

	bAlive = (select == 1) ? false : true;

	(bAlive == true) ? printf("��Ҵ�\n") : printf("�׾���\n");


	system("pause");
	return 0;
}