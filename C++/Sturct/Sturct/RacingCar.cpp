#include <iostream>
using namespace std;

#define MAX_SPD		200
namespace Sample //매크로 대신 namespace도 가능
{
	enum
	{
		ACC_STEP = 10, BRK_STEP = 10
	};
}

struct Car
{
	enum { ID_LEN = 20, FUEL_STEP = 2 }; //구조체 안에 정의함
	char gamerID[ID_LEN];	//소유자 ID, ID_LEN은 20이다
	int fuelGauge;			//연료량
	int curSpd;				//현재속도


	void ShowCarState() // 구조체 안에 전부 넣으면 끌어올 필요가 없다.
	{
		cout << "소유자 ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재속도: " << curSpd << "km/s" << endl;
	}
	void Accel(); //구조체 안에 먼저 선언 후 바깥으로 오버로딩 가능
};
void Car::Accel()
{
	if (fuelGauge <= 0) //연료가 0이나 그 보다 작으면 return
		return;
	else
		fuelGauge -= FUEL_STEP; //2만큼 감소

	if (curSpd + Sample::ACC_STEP >= MAX_SPD)
	{
		curSpd = MAX_SPD; //속도는 최고속도한계를 넘지 못한다
		return;
	}

	curSpd += Sample::ACC_STEP; //함수를 적용하는 만큼 속도는 ACC_STEP만큼 올라간다.
}

void Break(Car &car)
{
	if (car.curSpd <= 0)
	{
		car.curSpd = 0; //0밑으로의 감소는 없다.
		return;
	}

	car.curSpd -= Sample::BRK_STEP; //함수 호출 만큼 속도는 BRK_STEP만큼 감소한다.
}

int main()
{
	Car run99 = { "run99",100,0 }; //ID, 연료량, 현재속도
	run99.Accel(); //연료 2 감소, 속도 10 증가
	run99.Accel(); // 위와 동
	run99.ShowCarState();
	Break(run99); //속도 10 감소
	run99.ShowCarState();
	cout << endl;

	Car run0 = { "run0",100,0 };
	run0.Accel(); //연료 2 감소, 속도 10 증가
	run0.ShowCarState();
	Break(run0); //속도 10 감소
	Break(run0); 
	Break(run0); //계속 감소하지만 0 밑으로는 안내려간다.
	run0.ShowCarState();

	return 0;
}