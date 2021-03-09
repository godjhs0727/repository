#include <iostream> //���� recursive ���
#include <Windows.h>
#include <time.h>
using namespace std; //std:: ��������

namespace PlayerDev
{
	int atk = 10;
	void Print()
	{
		cout << "�÷��̾��� ���ݷ��� " << atk << "�̴�." << endl;
	}
}
namespace EnemyDev
{
	int atk = 2;
	void Print()
	{
		cout << "������ ���ݷ��� " << atk << "�̴�." << endl;
	}
}
using namespace PlayerDev;

int Add (int a, int b)
{
	return a + b;
}

void Print(int a, int b)
{
	cout << "����� : ";
	cout << Add(a, b) << endl;
}

void WhatIsRecursive(int startFloor, int bossFloor) //���ѹݺ��� ���� stack�޸𸮰� �� ���� ������.
{
	cout << "���� " << startFloor << "���� Ž�� ��" << endl;

	if (startFloor == bossFloor)
	{
		cout << startFloor << "������ ������ �����ߴ�." << endl; // 0->1->2->3->2->1->0
		return;
	}

	WhatIsRecursive(startFloor + 1, bossFloor); //���⼭ ���ܼ� ������ ���� �κк��� �ٽ� ���ư�

	cout << "���� " << startFloor << "������ ���� ���� ��" << endl; //���ѹݺ� ������ �������� ����� ���� ���Ѵ�.
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
	std::cout << "�Է� :";
	std::cin >> input;
	std::cout << input << std::endl;*/


	system("pause");
	return 0;
}