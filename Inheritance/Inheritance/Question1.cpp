/*
문제1
다음 클래스에 적절한 생성자를 삽입해보자. 그리고 이의 확인을 위한 main  함수를
적절히 정의해 보자
*/
#include <iostream>
#include <cstring>
using namespace std;

class Car //기본 연료 자동차
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

class HybridCar : public Car //하이브리드 자동차
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

class HybridWaterCar : public HybridCar //하이브리드 워커카
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec),waterGauge(water){}
	void ShowCurrentGauge()
	{
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};
/*
참고로, Car클래스는 가솔린으로 동작하는 자동차이고, HybridCar는 가솔린과 전기, HybridWaterCar는 가솔린과 전기, 그리고 물까지
*/
int main()
{
	HybridWaterCar wCar(79, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}