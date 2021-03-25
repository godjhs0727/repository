#include <iostream>
using namespace std;

#define MAX_SPD		200
namespace Sample //��ũ�� ��� namespace�� ����
{
	enum
	{
		ACC_STEP = 10, BRK_STEP = 10
	};
}

struct Car
{
	enum { ID_LEN = 20, FUEL_STEP = 2 }; //����ü �ȿ� ������
	char gamerID[ID_LEN];	//������ ID, ID_LEN�� 20�̴�
	int fuelGauge;			//���ᷮ
	int curSpd;				//����ӵ�


	void ShowCarState() // ����ü �ȿ� ���� ������ ����� �ʿ䰡 ����.
	{
		cout << "������ ID: " << gamerID << endl;
		cout << "���ᷮ: " << fuelGauge << "%" << endl;
		cout << "����ӵ�: " << curSpd << "km/s" << endl;
	}
	void Accel(); //����ü �ȿ� ���� ���� �� �ٱ����� �����ε� ����
};
void Car::Accel()
{
	if (fuelGauge <= 0) //���ᰡ 0�̳� �� ���� ������ return
		return;
	else
		fuelGauge -= FUEL_STEP; //2��ŭ ����

	if (curSpd + Sample::ACC_STEP >= MAX_SPD)
	{
		curSpd = MAX_SPD; //�ӵ��� �ְ�ӵ��Ѱ踦 ���� ���Ѵ�
		return;
	}

	curSpd += Sample::ACC_STEP; //�Լ��� �����ϴ� ��ŭ �ӵ��� ACC_STEP��ŭ �ö󰣴�.
}

void Break(Car &car)
{
	if (car.curSpd <= 0)
	{
		car.curSpd = 0; //0�������� ���Ҵ� ����.
		return;
	}

	car.curSpd -= Sample::BRK_STEP; //�Լ� ȣ�� ��ŭ �ӵ��� BRK_STEP��ŭ �����Ѵ�.
}

int main()
{
	Car run99 = { "run99",100,0 }; //ID, ���ᷮ, ����ӵ�
	run99.Accel(); //���� 2 ����, �ӵ� 10 ����
	run99.Accel(); // ���� ��
	run99.ShowCarState();
	Break(run99); //�ӵ� 10 ����
	run99.ShowCarState();
	cout << endl;

	Car run0 = { "run0",100,0 };
	run0.Accel(); //���� 2 ����, �ӵ� 10 ����
	run0.ShowCarState();
	Break(run0); //�ӵ� 10 ����
	Break(run0); 
	Break(run0); //��� ���������� 0 �����δ� �ȳ�������.
	run0.ShowCarState();

	return 0;
}