//�� Ŭ������ ������ �����ڿ� �Ҹ��ڸ� �����غ���. �׸��� ���� Ȯ���� ���� main�Լ��� �����غ���
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~MyFriendInfo()
	{
		delete[] name;
	}
	void ShowMyFriendInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char*myname, int myage, const char*myaddr, const char*myphone) :MyFriendInfo(myname, myage)
	{
		addr = new char[strlen(myaddr) + 1];
		phone = new char[strlen(myphone) + 1];
		strcpy(addr, myaddr);
		strcpy(phone, myphone);
	}
	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl;
	}
};
int main()
{
	MyFriendDetailInfo book("Lee", 25, "Seoul", "010-1111-2222");
	book.ShowMyFriendDetailInfo();
	return 0;
}