#include <stdio.h>
#include <Windows.h>
#include <string>

int main()
{/*
	int a;
	double b;
	printf("int : %d\n", sizeof(int));
	printf("char : %d\n", sizeof(char));
	printf("COORD : %d\n", sizeof(COORD));*/

	//struct Marine // struct : 구조체
	//{
	//	//멤버 변수
	//	int hp;
	//	int atk;
	//	int def;
	//	int range;
	//};

	//Marine unit1; //변수의 선언
	//unit1.hp = 45;
	//unit1.atk = 5;
	//unit1.def = 0;
	//unit1.range = 10;

	//printf("unit1의 체력 : %d\n", unit1.hp);
	//printf("unit1의 공격력 : %d\n", unit1.atk);
	//printf("unit1의 방어력 : %d\n", unit1.def);
	//printf("unit1의 사정거리 : %d\n", unit1.range);

	//Marine unit2;
	//unit2.atk = 100;
	//printf("unit1의 공격력\n", unit1.atk);
	//printf("unit2의 공격력\n", unit2.atk);

	COORD position; //coordination : 좌표
	position.X = 0;
	position.Y = 0;

	std::string player = "P";//큰따옴표는 문자열 작은따옴표는 아스키코드

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //void*

	

	while (true)
	{
		system("cls");

		if (GetAsyncKeyState('W') & 0x8000) //8000 : Press, 8001 : Down, 8002 : Up, 1001 : Toggle 록맨 참조
			position.Y--;//엔진마다 xy 좌표 기준이 다르다
		else if (GetAsyncKeyState('S') & 0x8000)
			position.Y++;

		if (GetAsyncKeyState('A') & 0x8000)
			position.X--;
		else if (GetAsyncKeyState('D') & 0x8000)
			position.X++;

		if (position.X <= 0)
			position.X = 0;
		if (position.Y <= 0)
			position.Y = 0;

		if (position.X > 15)
			position.X = 15;
		if (position.Y > 10)
			position.Y = 10;

		SetConsoleCursorPosition(handle, position);
		printf("%s", player.c_str());
	}
	   
	system("pause");
	return 0;
}