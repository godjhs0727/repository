#include "stdafx.h"

void Idle(){cout << "���" << endl;}
void Move() {cout << "�̵�" << endl;}
void Attack() {cout << "����" << endl;}
string Print(string name) { return "input : " + name; }
void Complete() { cout << "�Ϸ�" << endl; }
void Work(void(*callback)())
{
	for (int i = 0; i < 10; i++)
		cout << "�� �Լ��� ���� ���� ������ �ϴ� ��" << endl;
	
	callback();
}

int main()
{
	//void(*bp)(); //�Լ� ������ ������ ���� -> ������ void�̸鼭 �Ķ���Ͱ� ���� �Լ��� �ּҸ� ������ �� ����
	//bp = Attack; //�̸��� ������ �״�� �ּ��̴�. ��ȣ ����

	//bp(); //�Լ� ȣ���ϵ���

	//void(*bp[3])(); //�迭�� �����ڿ�
	//bp[0] = Idle;
	//bp[1] = Move;
	//bp[2] = Attack;

	//int behavior;
	//cout << "�ൿ �Է� : ";
	//cin >> behavior;
	////�ּҰ� �ִ� ���ֵ��� �����Ϳ� ������ �ִ�.

	//if (behavior == 0)
	//	Idle();
	//else if (behavior == 1)
	//	bp[1](); //����� ���� ����
	//else if (behavior == 2)
	//	Attack();

	//string result = Print("������"); //string Print(string name)
	//cout << result.c_str() << endl;

	//string(*sp)(string name); //string ������
	//sp = Print;

	//cout << sp("�̸�").c_str() << endl;

	//string str1 = "����";
	//string str2 = "����";
	//string result = str1 + str2; //������ �����ε� �÷��� ��ȣ�� ���ڶ� ���϶��� �ٸ���.
	//cout << result.c_str() << endl;

	//Callback
	void(*bp)() = Complete;

	Work(bp);
	cout << "==" << endl;
	Work(Idle);

	system("pause");
	return 0;
}