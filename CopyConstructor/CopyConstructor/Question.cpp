/*
문제 NameCard.cpp에 복사생성자를 적절히 활용해보자
*/

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
}
class NameCard
{
private:
	char* name;
	char* company;
	char* number;
	int position;
public:
	NameCard(const char* myname, const char* mycom, const char* phone, int pos)
		:position(pos)
	{
		name = new char[strlen(myname) + 1];
		company = new char[strlen(mycom) + 1];
		number = new char[strlen(phone) + 1];
		strcpy(name, myname);
		strcpy(company, mycom);
		strcpy(number, phone);
	}
	NameCard(const NameCard &copy) //깊은 복사를 위해
		:position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		company = new char[strlen(copy.company) + 1];
		number = new char[strlen(copy.number) + 1];
		strcpy(name, copy.name);
		strcpy(company, copy.company);
		strcpy(number, copy.number);
	}
	void ShowNameCardInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "번호: " << number << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard()
	{
		delete[] name;
		delete[] company;
		delete[] number;
	}
};

int main()
{
	NameCard man("Lee", "ABCEng", "010-1111-2222", COMP_POS::ASSIST);
	NameCard copy1 = man;
	NameCard man2("Jang", "OREng", "010-3333-4444", COMP_POS::MANAGER);
	NameCard copy2 = man2;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}