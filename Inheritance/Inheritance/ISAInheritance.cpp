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
		cout << "요청 내용을 계산합니다." << endl;
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
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
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
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, PenInfo) != 0) //string 비교
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};
int main()
{
	NotebookComp nc("Lee", 10); //컴퓨터 이름, 충전 잔량
	TableNotebook tn("Kim", 10, "PenName");
	nc.MovingCal();
	tn.Write("PenName");

	return 0;
}