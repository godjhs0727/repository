/*
씬에서 Get data
다음 Calc data계산
다음 Set Data 갱신

클래스의 특징
1. 캡슐화 (정보의 은닉성)
2. 상속
3. 다형성 (데이터 타입)

상속을 쓰는 이유
*/
#include "stdafx.h"

class Parent
{
public:
	Parent() { cout << "부모의 생성자가 호출됨" << endl; }
	~Parent() { cout << "부모의 소멸자가 호출됨" << endl; }
	void Func() { cout << "부모의 멤버함수가 호출됨" << endl; }
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
};

int main()
{
	{
		Child child;//생성자 소멸자 호출 순서 중요 만들어질때는 부모가 먼저 만들어지고 죽을때는 자식이 먼저 죽는다.
		child.Func();
		child.Value(99);
		child.Print();
	}


	system("pause");
	return 0;
}