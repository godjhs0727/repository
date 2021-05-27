#include <iostream>
#include <cstring>
using namespace std;

class Person //부모 클래스, 상위, 기초, 슈퍼
{
private:
	int age; //나이
	char name[50]; //이름
public:
	Person(int myage, const char* myname)
		:age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "MY name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person //Person으로부터 상속받았다. //자식클래스, 하위, 유도, 서브
{
private:
	char major[50]; //전공과목
public:
	UnivStudent(const char* myname, int myage, const char* mymajor)
		:Person(myage, myname)
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main()
{
	UnivStudent ustd1("Lee", 22, "eng.");
	ustd1.WhoAreYou();


	return 0;
}