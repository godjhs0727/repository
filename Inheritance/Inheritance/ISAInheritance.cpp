#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};
class NotebookComp : public Computer
{
private:
	int Battery;
public:
	NotebookComp(const char*name, int initChag)
		:Computer(name),Battery(initChag)
	{}
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	int GetBatteryInfo() { return Battery; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
};
class TableNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TableNotebook(const char*name, int initChag, const char* pen)
		:NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void Write(const char* PenInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, PenInfo) != 0) //string ��
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};
int main()
{
	NotebookComp nc("Lee", 10); //��ǻ�� �̸�, ���� �ܷ�
	TableNotebook tn("Kim", 10, "PenName");
	nc.MovingCal();
	tn.Write("PenName");

	return 0;
}