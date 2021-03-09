#include <iostream> //제목 recursive 재귀
#include <Windows.h>
#include <time.h>
using namespace std; //std:: 생략가능

namespace PlayerDev
{
	int atk = 10;
	void Print()
	{
		cout << "플레이어의 공격력은 " << atk << "이다." << endl;
	}
}
namespace EnemyDev
{
	int atk = 2;
	void Print()
	{
		cout << "몬스터의 공격력은 " << atk << "이다." << endl;
	}
}
using namespace PlayerDev;

int Add (int a, int b)
{
	return a + b;
}

void Print(int a, int b)
{
	cout << "결과는 : ";
	cout << Add(a, b) << endl;
}

void WhatIsRecursive(int startFloor, int bossFloor) //무한반복문 쓰면 stack메모리가 꽉 차서 터진다.
{
	cout << "현재 " << startFloor << "층을 탐색 중" << endl;

	if (startFloor == bossFloor)
	{
		cout << startFloor << "층에서 보스와 조우했다." << endl; // 0->1->2->3->2->1->0
		return;
	}

	WhatIsRecursive(startFloor + 1, bossFloor); //여기서 끊겨서 나머지 끊긴 부분부터 다시 돌아감

	cout << "현재 " << startFloor << "층에서 돌아 오는 중" << endl; //무한반복 끝나기 전까지는 여기로 오지 못한다.
}

int main()
{
	srand((UINT)time(NULL));

	//WhatIsRecursive(1, rand() % 10 + 1);

	/*Print(5, 15); */
	//PlayerDev::atk = 99;
	//PlayerDev::Print();
	//scanf -> cin
	//printf -> cout

	/*int input;
	std::cout << "입력 :";
	std::cin >> input;
	std::cout << input << std::endl;*/


	system("pause");
	return 0;
}