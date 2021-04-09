/*
����1
���� Ŭ������ ������ �����ڸ� �����غ���. �׸��� ���� Ȯ���� ���� main  �Լ���
������ ������ ����
*/
#include <iostream>
#include <cstring>
using namespace std;

class Car //�⺻ ���� �ڵ���
{
private:
	int gasolinGauge;
public:
	Car(int gas) : gasolinGauge(gas){}
	int GetGasGauge()
	{
		return gasolinGauge;
	}
};

class HybridCar : public Car //���̺긮�� �ڵ���
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec) : Car(gas),electricGauge(elec){}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar //���̺긮�� ��Ŀī
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec),waterGauge(water){}
	void ShowCurrentGauge()
	{
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};
/*
�����, CarŬ������ ���ָ����� �����ϴ� �ڵ����̰�, HybridCar�� ���ָ��� ����, HybridWaterCar�� ���ָ��� ����, �׸��� ������
*/
int main()
{
	HybridWaterCar wCar(79, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}