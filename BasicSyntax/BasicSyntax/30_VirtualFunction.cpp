#include "stdafx.h"

class Parent
{
public:
	Parent() { cout << "�θ��� �����ڰ� ȣ���" << endl; }
	virtual ~Parent() { cout << "�θ��� �Ҹ��ڰ� ȣ���" << endl; } //�θ��� �Ҹ��ڿ� virtual�� �ٿ���� �ڽ��� �Ҹ��ڵ� ����?
	virtual void Func() { cout << "�θ��� ����Լ��� ȣ���" << endl; }//�����Լ�
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
	void Func() override { cout << "�ڽ��� ��� �Լ��� ȣ���" << endl; } //�������̵带 ���δ�.
	void Onlychild() { cout << "���� �ڽĸ��� ���� ����̴�." << endl; }

};

int main()
{
	//������?
	cout << "�ڱ� �ڽ����� �����Ҵ�" << endl;
	Child* child = new Child;
	child->Value(10);
	child->Print();
	delete child;

	cout << "��ĳ����" << endl;
	Parent*obj = new Child; //Parent Ÿ�Ե� �����ϴ�. �����Ҵ��� �ƴҶ��� ���� �Լ��϶� �ڽ� �Լ��� ȣ�� �ȴ�.
	obj->Func();
	delete obj;

	cout << "�ٿ�ĳ����" << endl;
	((Child*)obj)->Onlychild();
	//�ڽ��̶� �θ�� ���� �̸��� �Լ��� �ڽĲ��� ���� ������ �����Լ��� ���� ����
	//�������̵��� �Ѵ�. �����ε��� �Ķ���ͷ� ����, �������̵��� �θ��ڽİ�����
	//Ŭ������ ���迡 ���� ������ �ϴ°� �������̵�

	Child c;

	system("pause");
	return 0;
}