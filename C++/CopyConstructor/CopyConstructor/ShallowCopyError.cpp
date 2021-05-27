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
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
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
	Person man2 = man1; //�׳� �ϸ� default��������ڰ� ���� �Ҹ��ڼ��� �� �ҷ��ͼ� �� 17�� �ʿ��ϴ�. ���� ���� ���� ���� ����
	//���� ����� ������� age�� ��� �� ��� ����, �޸� ���� �Ҵ��� ���ڿ� ����, �׸��� �Ҵ�� �޸��� �ּ� ���� ��� name�� ���� �� �Ѵ�.
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();


	return 0;
}
