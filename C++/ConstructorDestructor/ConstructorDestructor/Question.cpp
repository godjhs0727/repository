#include <iostream>
#include <cstring>
using namespace std;
/*
����)
������ �ǹ��ϴ� NameCard Ŭ������ �����غ���. �� Ŭ�������� ������ ������ ����Ǿ�� �Ѵ�.
����, ȸ���̸�, ��ȭ��ȣ, ����
��, ���� ������ ������ �������� ���ڿ��� ���·� ������ �ϵ�, ���̿� �� �´� �޸� ������ ��
�� �޴� ���·� ��������(���� �Ҵ��϶�� �ǹ��̴�). �׸��� ���� ������ int�� ��������� ������
�� ������ �ϵ�, �Ʒ��� enum ������ Ȱ���ؾ� �Ѵ�.
*/
namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
}
/*
���� enum ���𿡼� ���ǵ� ����� ������� ���, ����, �븮, ������ ���Ѵ�. �׷� ���� main
�Լ��� ������ ���� �����Ͽ�, �� �������� ���ϴ� ���´�� NameCard Ŭ�������� �ϼ��غ���.
*/
class NameCard
{
private:
	char* myName;
	char* myCompany;
	char* myPhone;
	int position;

public:
	NameCard(const char* name, const char* company, const char* phone, int pos)
		:position(pos)
	{
		myName = new char[strlen(name) + 1];
		myCompany = new char[strlen(company) + 1];
		myPhone = new char[strlen(phone) + 1];
		strcpy(myName, name);
		strcpy(myCompany, company);
		strcpy(myPhone, phone);
	}
	void ShowNameCardInfo()
	{
		cout << "�̸�: " << myName << endl;
		cout << "ȸ��: " << myCompany << endl;
		cout << "��ȭ��ȣ: " << myPhone << endl;
		cout << "����: "; COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard()
	{
		delete[] myName;
		delete[] myCompany;
		delete[] myPhone;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}