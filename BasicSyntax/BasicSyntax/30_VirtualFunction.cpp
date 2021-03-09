#include "stdafx.h"

class Parent
{
public:
	Parent() { cout << "부모의 생성자가 호출됨" << endl; }
	virtual ~Parent() { cout << "부모의 소멸자가 호출됨" << endl; } //부모의 소멸자에 virtual을 붙여줘야 자식의 소멸자도 가능?
	virtual void Func() { cout << "부모의 멤버함수가 호출됨" << endl; }//가상함수
	void Print() { cout << "값 : " << value << endl; }

protected:
	void Value_Parent(int val) { value = val; }

private:
	int value;
};

class Child : public Parent
{
public:
	Child() { cout << "자식의 생성자가 호출됨" << endl; }
	~Child() { cout << "자식의 소멸자가 호출됨" << endl; }//소멸자는 리턴도 없고 파라미터도 없다.

	void Value(int val) { Value_Parent(val); }
	void Func() override { cout << "자식의 멤버 함수가 호출됨" << endl; } //오버라이드를 붙인다.
	void Onlychild() { cout << "나는 자식만의 고유 기능이다." << endl; }

};

int main()
{
	//다형성?
	cout << "자기 자신으로 동적할당" << endl;
	Child* child = new Child;
	child->Value(10);
	child->Print();
	delete child;

	cout << "업캐스팅" << endl;
	Parent*obj = new Child; //Parent 타입도 가능하다. 동적할당이 아닐때는 같은 함수일때 자식 함수가 호출 된다.
	obj->Func();
	delete obj;

	cout << "다운캐스팅" << endl;
	((Child*)obj)->Onlychild();
	//자식이랑 부모랑 같은 이름의 함수를 자식꺼를 쓰고 싶으면 가상함수를 만들어서 쓴다
	//오버라이드라고 한다. 오버로딩은 파라미터로 구분, 오버라이딩은 부모자식관계의
	//클래스의 관계에 따라 재정의 하는게 오버라이드

	Child c;

	system("pause");
	return 0;
}