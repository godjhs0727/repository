#include <iostream>
using namespace std;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gamerID[ID_LEN];	//소유자 ID, ID_LEN은 20이다
	int fuelGauge;			//연료량
	int curSpd;				//현재속도
};

void ShowCarState(const Car &car) //정보만 주고 수정 안하니 상수화해서 const화 시킨다.
{
	cout << "소유자 ID: " << car.gamerID << endl;
	cout << "연료량: " << car.fuelGauge << "%" << endl;
	cout << "현재속도: " << car.curSpd << "km/s" << endl;
}

void Accel(Car &car)
{
	if (car.fuelGauge <= 0) //연료가 0이나 그 보다 작으면 return
		return;
	else
		car.fuelGauge -= FUEL_STEP; //2만큼 감소

	if (car.curSpd + ACC_STEP >= MAX_SPD)
	{
		car.curSpd = MAX_SPD; //속도는 최고속도한계를 넘지 못한다
		return;
	}

	car.curSpd += ACC_STEP; //함수를 적용하는 만큼 속도는 ACC_STEP만큼 올라간다.
}

void Break(Car &car)
{
	if (car.curSpd <= 0)
	{
		car.curSpd = 0; //0밑으로의 감소는 없다.
		return;
	}

	car.curSpd -= BRK_STEP; //함수 호출 만큼 속도는 BRK_STEP만큼 감소한다.
}

int main()
{
	Car run99 = { "run99",100,0 }; //ID, 연료량, 현재속도
	Accel(run99); //연료 2 감소, 속도 10 증가
	Accel(run99); // 위와 동
	ShowCarState(run99);
	Break(run99); //속도 10 감소
	ShowCarState(run99);
	cout << endl;

	Car run0 = { "run0",100,0 };
	Accel(run0); //연료 2 감소, 속도 10 증가
	ShowCarState(run0);
	Break(run0); //속도 10 감소
	Break(run0); 
	Break(run0); //계속 감소하지만 0 밑으로는 안내려간다.
	ShowCarState(run0);

	return 0;
}