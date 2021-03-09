//Object Oriented Programming
#include "stdafx.h"

const short Width = 100;
const short Height = 50;

class Unit
{
public:
	//��� �Լ�
	//������
	Unit(string symbol, int atk, int hp)
		: moveSpeed(1)
		, attackRange(0)
		, symbol(symbol) //�ʱ�ȭ ������ �� ����
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
	void Render()//ȭ���� �׷��ִ� ����
	{
		SetConsoleCursorPosition(/*this������ ����*/handle, position);
		cout << symbol.c_str();
	}

public:
	void Position(short x, short y)
	{
		this->position = { x, y };
	}//������ �ձ��� �ҹ��� �Լ��� �빮��

	COORD Position()
	{
		return position;
	}
	void AttackRange(int val)
	{
		attackRange = val;
	}

	bool CheckInRange(const Unit* target/*�Ÿ� �˻縦 �ϰ��� �ϴ� ��� �ȿ� ������ Ʈ�� ���̸� ����*/)
	{
		short distanceX = (short)abs(target->position.X - this->position.X);
		short distanceY = (short)abs(target->position.Y - this->position.Y);

		short distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		cout << "Distance(Vec2) : " << distanceX << ", " << distanceY << endl;
		cout << "Distance(Scalar) : " << distance << endl;

		if (distance > attackRange)
		{
			cout << "�����Ÿ� ��" << endl;
			return false;
		}
		cout << "�����Ÿ� ��" << endl;
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
	//��� ����
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
			//���۸��� ü�°� ������ ���ݷ��� ���´�. getter �Ķ���Ͱ� ����
			int hp = zergling->HP();
			int atk = marine->Attack();

			//������ ���ݷ¸�ŭ ���۸��� ü���� ��´�. calculate
			hp -= atk;

			//���� ü���� ���۸����� �ݿ����ش�. setter �Ķ���Ͱ� �ִ�
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