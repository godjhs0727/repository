/*
������ Get data
���� Calc data���
���� Set Data ����

Ŭ������ Ư¡
1. ĸ��ȭ (������ ���м�)
2. ���
3. ������ (������ Ÿ��)

����� ���� ����
*/
#include "stdafx.h"

class Parent
{
public:
	Parent() { cout << "�θ��� �����ڰ� ȣ���" << endl; }
	~Parent() { cout << "�θ��� �Ҹ��ڰ� ȣ���" << endl; }
	void Func() { cout << "�θ��� ����Լ��� ȣ���" << endl; }
	void Print() { cout << "�� : " << value << endl; }

protected:
	void Value_Parent(int val) { value = val; }

private:
	int value;
};

class Child : public Parent
{
public:
	Child() { cout << "�ڽ��� �����ڰ� ȣ���" << endl; }
	~Child() { cout << "�ڽ��� �Ҹ��ڰ� ȣ���" << endl; }//�Ҹ��ڴ� ���ϵ� ���� �Ķ���͵� ����.

	void Value(int val) { Value_Parent(val); }
};

int main()
{
	{
		Child child;//������ �Ҹ��� ȣ�� ���� �߿� ����������� �θ� ���� ��������� �������� �ڽ��� ���� �״´�.
		child.Func();
		child.Value(99);
		child.Print();
	}


	system("pause");
	return 0;
}