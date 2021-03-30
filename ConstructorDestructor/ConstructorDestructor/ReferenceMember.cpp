//이니셜라이저의 이러한 특징은 멤버변수로 참조자를 선언할 수 있게 한다.
#include <iostream>
using namespace std;

class AAA
{
public:
	AAA(int n)
	{
		cout << "n = " << n << endl;
	}
	AAA()
	{
		cout << "empty object" << endl;
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA *ptr = new AAA(10);
	AAA &ref;
	const int &num;
public:
	BBB(AAA &r, const int &n)
		:ref(r), num(n){};
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
	~BBB()
	{
		delete ptr; //동적할당 삭제
		cout << "destructor" << endl;
	}
};

int main()
{
	//참조자도 const변수와 마찬가지로 선언과 동시에 초기화가 이뤄져야 한다.
	//따라서 이니셜라이저를 이용하면 참조자도 멤버변수로 선언될 수 있다.
	AAA obj1; //여기서 AAA 생성자 발동
	BBB obj2(obj1, 20); //BBB private에 있는 동적할당 생성자가 호출됨, 이니셜라이저로 초기화 저장
	obj2.ShowYourName(); //첫줄 코드에 의해서 AAA의 void함수 호출, 그 다음 줄 코드, 다음 줄 코드 순서대로 끝날때 소멸자 호출되어서 new할당 삭제

	return 0;
}