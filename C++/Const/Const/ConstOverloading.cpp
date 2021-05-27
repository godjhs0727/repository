#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n) {}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple &obj)
{
	obj.SimpleFunc();
}

int main()
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc(); //일반은 일반멤버함수가
	obj2.SimpleFunc(); //const는 const멤버함수가

	YourFunc(obj1); //25행에 정의된 YourFunc 함수는 전달되는 인자를 참조자로, const참조자로 받는다. 따라서 19행의 const 멤버함수가 호출된다.
	YourFunc(obj2);

	return 0;
}