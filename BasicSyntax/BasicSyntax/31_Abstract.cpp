#include "stdafx.h"

class Parent//<-�߻� Ŭ���� ���������Լ��� �ϳ��� �ִ°�
{
public:
	virtual void Func() = 0;//<- ���� ���� �Լ� ��ü�� ��� ������ �ڽ��� ������ �Ѵ�. : �ڽ� Ŭ�������� ������ ������(�������̵�) �ؾ���
};

class Child : public Parent
{
	// Parent��(��) ���� ��ӵ�
	virtual void Func() override
	{
		cout << "�籸���� ���������Լ�" << endl;
	}
	/*void Func() override { cout << "�����ǵ� ���������Լ�" << endl; }*/
};

int main()
{
	/*Child obj;*/
	//Parent obj2; <- �߻� Ŭ������ �޸� ���ÿ� �ø� �� ����
	Parent *obj = new Child;
	obj->Func();
	delete obj;

	system("pause");
	return 0;
}