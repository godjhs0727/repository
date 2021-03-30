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
		name = new char[len]; //���ʿ��� �޸� ������ ���� �Ǵ� ������ ���� ���� ���ڿ��� ���̸�ŭ �޸� ������ ���� �Ҵ�
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person() //�Ҹ��ڿ��� �����ڿ��� �Ҵ��� �޸� ������ �Ҹ꿡 ���� �ڵ尡 ����
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