#include "stdafx.h"
// ./�� ��� ���../../�Ҷ����� ��������
void Swap(int a, int b);
void Swap(int* a, int* b);
void SwapReference(int& a, int& b);

double globalVar = 77; //�����������ٴ� Call By Address ������ ����ϴ°� ��õ

void SetGlobal(double val);

int main()
{
	int a = 10, b = 1;

	//Call By Value
	cout << "���� �� : " << a << ", " << b << endl;
	Swap(a, b);
	cout << "���� �� : " << a << ", " << b << endl;

	//Call By Address
	cout << "���� �� : " << a << ", " << b << endl;
	Swap(&a, &b);
	cout << "���� �� : " << a << ", " << b << endl;

	//Reference
	int& ref = a;
	cout << &a << endl;
	cout << &ref << endl;

	//Call By Reference  Adressó�� ������ �ٲܼ��� �ְ� �޸� ������ ������ ������.
	cout << "���� �� : " << a << ", " << b << endl;
	SwapReference(a, b);
	cout << "���� �� : " << a << ", " << b << endl;

	cout << "���� ���� : " << globalVar << endl;
	SetGlobal(99);
	cout << "���� ���� : " << globalVar << endl;

	//���
	const float PI = 3.141592f; //������ �Ǹ� �ȵǴ� ������ const
	// ���� ; PI = 10.0f;
	//static
	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		int count = 1;
		num = count++;
	}
	cout << "�Ϲ� ���� : " << num << endl;

	for (int i = 0; i < 3; i++)
	{
		static int count = 1; //����ƽ ������ �ѹ��� ����ϰ� ��� ���� �ȴ�. ������ �� �Ǹ� ���õȴ�.
		num = count++;
	}
	cout << "����ƽ ���� : " << num << endl;

	system("pause");
	return 0;
}

void Swap(int a, int b)
{
	int c = a;
	a = b;
	b = c;

}

void Swap(int * a, int * b) //�����簡 �߻��ϰ� �޸� ���� �Ҵ��� �ʿ��ϰ� �ּҰ��� �ٲٰ�
{
	int c = *a;
	*a = *b;
	*b = c;
}

void SwapReference(int & a, int & b) //������ �ʿ� ���� �޸� ���� �Ҵ絵 �ʿ���� �ּҰ��� ���� �ٲ��ʿ���� ������ ȿ���� ����.
{
	int c = a;
	a = b;
	b = c;
}

void SetGlobal(double val)
{
	globalVar = val;
}
