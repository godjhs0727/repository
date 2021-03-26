#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMember(const char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelgauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "ID: " << gamerID << endl;
	cout << "연료량: " << fuelgauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;
}

void Car::Accel()
{
	if (fuelgauge <= 0)
		return;
	else
		fuelgauge -= CAR_CONST::FUEL_STEP;

	if (curSpeed >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	else
		curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed <= 0)
	{
		curSpeed = 0;
		return;
	}
	else
		curSpeed -= CAR_CONST::BRK_STEP;
}
