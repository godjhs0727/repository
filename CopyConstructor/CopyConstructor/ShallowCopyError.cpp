#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person &copy) :age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	void ShowPersonInfo()const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};
int main()
{
	Person man1("Lee", 20);
	Person man2 = man1; //그냥 하면 default복사생성자가 생겨 소멸자순간 못 불러와서 행 17이 필요하다. 얕은 복사 깊은 복사 차이
	//깊은 복사는 멤버변수 age의 멤버 대 멤버 복사, 메모리 공간 할당후 문자열 복사, 그리고 할당된 메모리의 주소 값을 멤버 name에 저장 을 한다.
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();


	return 0;
}
