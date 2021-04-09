//두 클래스에 적절한 생성자와 소멸자를 정의해보자. 그리고 이의 확인을 위한 main함수를 정의해보자
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
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
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
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}
};
int main()
{
	MyFriendDetailInfo book("Lee", 25, "Seoul", "010-1111-2222");
	book.ShowMyFriendDetailInfo();
	return 0;
}