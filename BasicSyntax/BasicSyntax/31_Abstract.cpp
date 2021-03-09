#include "stdafx.h"

class Parent//<-추상 클래스 순수가상함수가 하나라도 있는거
{
public:
	virtual void Func() = 0;//<- 순수 가상 함수 몸체가 없어서 무조건 자식이 만들어야 한다. : 자식 클래스에서 무조건 재정의(오버라이딩) 해야함
};

class Child : public Parent
{
	// Parent을(를) 통해 상속됨
	virtual void Func() override
	{
		cout << "재구현된 순수가상함수" << endl;
	}
	/*void Func() override { cout << "재정의된 순수가상함수" << endl; }*/
};

int main()
{
	/*Child obj;*/
	//Parent obj2; <- 추상 클래스는 메모리 스택에 올릴 수 없음
	Parent *obj = new Child;
	obj->Func();
	delete obj;

	system("pause");
	return 0;
}