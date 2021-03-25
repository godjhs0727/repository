#include <iostream>
using namespace std;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gamerID[ID_LEN];	//������ ID, ID_LEN�� 20�̴�
	int fuelGauge;			//���ᷮ
	int curSpd;				//����ӵ�


	void ShowCarState() // ����ü �ȿ� ���� ������ ����� �ʿ䰡 ����.
	{
		cout << "������ ID: " << gamerID << endl;
		cout << "���ᷮ: " << fuelGauge << "%" << endl;
		cout << "����ӵ�: " << curSpd << "km/s" << endl;
	}
};
void Accel(Car &car)
{
	if (car.fuelGauge <= 0) //���ᰡ 0�̳� �� ���� ������ return
		return;
	else
		car.fuelGauge -= FUEL_STEP; //2��ŭ ����

	if (car.curSpd + ACC_STEP >= MAX_SPD)
	{
		car.curSpd = MAX_SPD; //�ӵ��� �ְ��ӵ��Ѱ踦 ���� ���Ѵ�
		return;
	}

	car.curSpd += ACC_STEP; //�Լ��� �����ϴ� ��ŭ �ӵ��� ACC_STEP��ŭ �ö󰣴�.
}

void Break(Car &car)
{
	if (car.curSpd <= 0)
	{
		car.curSpd = 0; //0�������� ���Ҵ� ����.
		return;
	}

	car.curSpd -= BRK_STEP; //�Լ� ȣ�� ��ŭ �ӵ��� BRK_STEP��ŭ �����Ѵ�.
}

int main()
{
	Car run99 = { "run99",100,0 }; //ID, ���ᷮ, ����ӵ�
	Accel(run99); //���� 2 ����, �ӵ� 10 ����
	Accel(run99); // ���� ��
	run99.ShowCarState();
	Break(run99); //�ӵ� 10 ����
	run99.ShowCarState();
	cout << endl;

	Car run0 = { "run0",100,0 };
	Accel(run0); //���� 2 ����, �ӵ� 10 ����
	run0.ShowCarState();
	Break(run0); //�ӵ� 10 ����
	Break(run0); 
	Break(run0); //��� ���������� 0 �����δ� �ȳ�������.
	run0.ShowCarState();

	return 0;
}