#include <stdio.h>
#include <Windows.h>
//�����Ҵ�
int main()
{
	//int* ptr; //int�����͵� double�����͵� �� ��Ʈ ü���̴��Ŀ� ���� 4����Ʈ Ȥ�� 8����Ʈ
	////�����ʹϱ� 4����Ʈ new double�� ������ heap ������ 8����Ʈ�� ���� �ȴ�.


	//ptr = new int; //heap ������ 4����Ʈ�� ��û�Ѵ�. new�� ������ ���α׷��� ���� �ʴ´�?
	//*ptr = 50;
	//printf("���� �Ҵ� ���� �ּ� : %x\n", ptr);
	//printf("���� �Ҵ� ���� �ּҿ� ��� �ִ� �� : %d\n", *ptr);
	//delete ptr; //�ȿ� ���� �״������ ����Ǿ� �ִ� ��ũ�� ��������.
	//
	//
	
	printf("�л��� �� : ");
	int input;
	scanf("%d", &input);
	
	int* student = new int[input]; //new�� ���ָ� �ݵ�� delete�� ���־�� �Ѵ�.
	int score;

	//�Է�
	printf("���� �Է� ����\n");
	for (int i = 0; i < input; i++)
	{
		printf("%d ��° �Է� : ", i);
		scanf("%d", &student[i]);
		
	}

	//���
	printf("��� ����\n");
	
	for (int i = 0; i < input; i++)
	{
		printf("%d ��° ��� %d\n",i, *(student + i));// ==student[i]
	}
	
	delete[] student;//�ݵ�� �迭��ȣ[]�� ���;� �Ѵ�.

	int *pp = new int;
	*pp = 30;
	delete pp;
	printf("%d\n", *pp);

	/*int arr[3] = { 100, 200, 300 };
	printf("%x\n", arr);
	printf("%x\n", &arr[0]);
	printf("%x\n", &arr[1]);
	printf("%x\n", &arr[2]);

	printf("%d\n", *(arr + 1));
	printf("%d\n", arr[1]);*/

	system("pause");
	return 0;
}


// -> �Լ� : Function, prededure(���ν���)
// -> Call By Value
// -> Call By Address
// -> Call By Reference ���� ����