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
		int len = strlen(myname) + 1;
		name = new char[len]; //불필요한 메모리 공간의 낭비 또는 부족을 막기 위해 문자열의 길이만큼 메모리 공간을 동적 할당
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person() //소멸자에는 생성자에서 할당한 메모리 공간의 소멸에 대한 코드가 삽입
	{
		delete[] name;
		cout << "called destructor" << endl;
	}
};

int main()
{
	Person man1("Lee", 20);
	Person man2("Jang", 31);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}