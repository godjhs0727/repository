#pragma once
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
		ACC_STEP = 10, BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelgauge;
	int curSpeed;
public:
	void InitMember(const char*ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};