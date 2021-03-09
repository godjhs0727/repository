//Object Oriented Programming
#include "stdafx.h"

const short Width = 100;
const short Height = 50;

class Unit
{
public:
	//멤버 함수
	//생성자
	Unit(string symbol, int atk, int hp)
		: moveSpeed(1)
		, attackRange(0)
		, symbol(symbol) //초기화 순서가 더 빠름
		, atk(atk)
		, hp(hp)
		, position({0, 0})
	{
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
		/*this->symbol = symbol;
		this->atk = atk;
		this->hp = hp;
		position = { 0, 0 };*/
	}

	void Move()
	{
		if (GetAsyncKeyState('A') & 0x8000)
			position.X -= (position.X > 0) ? moveSpeed : 0;
		else if (GetAsyncKeyState('D') & 0x8000)
			position.X += (position.X < Width) ? moveSpeed : 0;

		if (GetAsyncKeyState('W') & 0x8000)
			position.Y -= (position.Y > 0) ? moveSpeed : 0;
		else if (GetAsyncKeyState('S') & 0x8000)
			position.Y += (position.Y < Height) ? moveSpeed : 0;
	}

public:
	void Update()
	{
		if (hp <= 0)
			hp = 0;
	}
	void Render()//화면을 그려주는 역할
	{
		SetConsoleCursorPosition(/*this포인터 생략*/handle, position);
		cout << symbol.c_str();
	}

public:
	void Position(short x, short y)
	{
		this->position = { x, y };
	}//변수는 앞글자 소문자 함수는 대문자

	COORD Position()
	{
		return position;
	}
	void AttackRange(int val)
	{
		attackRange = val;
	}

	bool CheckInRange(const Unit* target/*거리 검사를 하고자 하는 대상 안에 들어오면 트루 밖이면 풜스*/)
	{
		short distanceX = (short)abs(target->position.X - this->position.X);
		short distanceY = (short)abs(target->position.Y - this->position.Y);

		short distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		cout << "Distance(Vec2) : " << distanceX << ", " << distanceY << endl;
		cout << "Distance(Scalar) : " << distance << endl;

		if (distance > attackRange)
		{
			cout << "사정거리 밖" << endl;
			return false;
		}
		cout << "사정거리 안" << endl;
		return true;

	}

	int Attack()
	{
		return atk;
	}
	int HP()
	{
		return hp;
	}

	void HP(int val)
	{
		hp = val;
	}


private:
	//멤버 변수
	string symbol;
	COORD position;
	const short moveSpeed;
	int atk;
	int hp;

	int attackRange;

	HANDLE handle; 

};


int main()
{
	Unit* marine = new Unit("M", 2, 45);
	marine->Position(8, 8);
	marine->AttackRange(5);

	Unit* zergling = new Unit("Z", 5, 200);
	zergling->Position(12, 14);

	while (true)
	{
		system("cls");
		cout << zergling->HP() << endl;

		marine->Move();

		if (marine->CheckInRange(zergling) == true)
		{
			//저글링의 체력과 마린의 공격력을 얻어온다. getter 파라미터가 없는
			int hp = zergling->HP();
			int atk = marine->Attack();

			//마린의 공격력만큼 저글링의 체력을 깎는다. calculate
			hp -= atk;

			//깎인 체력을 저글링에게 반영해준다. setter 파라미터가 있는
			zergling->HP(hp);
		}


		marine->Update();
		zergling->Update();

		marine->Render();
		zergling->Render();
	}

	system("pause");
	return 0;
}