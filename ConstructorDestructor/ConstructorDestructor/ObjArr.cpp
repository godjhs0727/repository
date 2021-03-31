//��ü�迭 �˾ƺ���
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
	Person() //�迭 ������ ������ default ������
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	//void SetPersonInfo(const char* myname, int myage) //���ϴ� �����ͷ��� �ʱ�ȭ�� �������� ���ǵ� �Լ��̴�. �����ص� ����
	//{
	//	name = myname;
	//	age = myage;
	//}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << ", ";
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor" << endl;
	}
};

int main()
{
	Person* parr[3];
	char namestr[100];
	char* strptr;
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�: ";
		cin >> namestr;
		cout << "����: ";
		cin >> age;
		/*strptr = new char[strlen(namestr) + 1];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);*/
		parr[i] = new Person(namestr, age);

	}
	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];

	return 0;
}