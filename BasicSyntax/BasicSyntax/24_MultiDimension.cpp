#include "stdafx.h"

void InitArray(int* begin,int size);
void PrintArray(int*begin, int size);
void SetValue(int** ptr);

int main()
{
	////�迭�� �̸��� �����ּҸ� ����Ű�� ������
	////2���� �迭
	//int d1Arr[] = { 1,2,3 }; //�߰�ȣ �ʱ�ȭ �ϸ� �տ� �Ⱦ��� �ִ�.
	//int d2Arr[][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } }; //00,01,02,03 ,10,11,12,13, 20,21,22,23

	//cout << " [0] �ּ�" << d2Arr[0] << endl; //d2Arr[0][0]~[3]�� ���� �ּ� 4*4 16 �׷��� �Ʒ��� 16���� 16���� �迭�� ��ü �����ּ�
	//cout << " [1] �ּ�" << d2Arr[1] << endl;//������ 1���� ���� ���� �ּ�
	//cout << "[1][0] �ּ� " << &d2Arr[1][0] << endl; //�ι�°�� ����

	////�迭�� �Ķ���ͷ� �ѱ�� ��
	//int capacity;
	//cout << "�迭�� ũ�⸦ �������ּ��� : ";
	//cin >> capacity;
	//
	//int*arr = new int[capacity]; //�� �Ҵ� �ؼ� �� ���� ����

	//InitArray(arr, capacity);
	//PrintArray(arr, capacity);

	//cout << "---------------------\n";
	//int normalArr[5] = { 100,200,300,400,500 };
	//PrintArray(normalArr, 5);
	//int* param = arr;
	//int* ptr;
	//int a = 100;
	//ptr = &a;

	//SetValue(ptr); //Call By Address

	//cout << a << endl; //a �� �ּҰ�

	//���� ������
	int* a = NULL;
	SetValue(&a);
	cout << *a << endl;

	//double b = 2;
	//double* ptr = &b; //�������� �ּҸ� �����ϴ� Ÿ���� �����������̴�.
	//double** ptr2 = &ptr; //���������͵� ���ú����� ���� �ּҰ� �� �ִ�.

	//cout << ptr2 << endl; //ptr2�� ��, ptr�� �ּ�
	//cout << *ptr2 << endl; //ptr�� ��, b�� �ּ�
	//cout << **ptr2 << endl; // b�� ��

	//void*
	//int arr[3] = { 1,2,3 };
	//cout << *(arr + 2) << endl; //2�� �ε����� �����ּ�
	double number = 2020; //�������°� 8 ����Ʈ�� �������°ͱ��� �������� ������ pPtr = int &number �� �Ұ�����
	void* vPtr = &number; //void�� �ƹ��ų� �� ������ �ִ�.
	cout << *(double*)vPtr << endl; //void�� ��õǾ����� �ʱ⶧���� ������ Ÿ���� �տ� ���־����

	system("pause");
	return 0;
}

void InitArray(int * begin, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(begin + i) = i; //�����͵� �迭�� �����ϴ�. b[i] == *(b + 1)
	}
}

void PrintArray(int * begin, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << begin[i] << endl; //�ε�����ŭ �ǳʶٴ� �������̴�.
	}
}

void SetValue(int ** ptr)
{
	*ptr = new int;
	**ptr = 999;
}
