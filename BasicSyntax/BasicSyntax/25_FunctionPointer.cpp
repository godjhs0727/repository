#include "stdafx.h"

void Idle(){cout << "대기" << endl;}
void Move() {cout << "이동" << endl;}
void Attack() {cout << "공격" << endl;}
string Print(string name) { return "input : " + name; }
void Complete() { cout << "완료" << endl; }
void Work(void(*callback)())
{
	for (int i = 0; i < 10; i++)
		cout << "이 함수는 뭔가 일을 열심히 하는 중" << endl;
	
	callback();
}

int main()
{
	//void(*bp)(); //함수 포인터 변수의 선언 -> 리턴이 void이면서 파라미터가 없는 함수의 주소를 저장할 수 있음
	//bp = Attack; //이름만 넣으면 그대로 주소이다. 괄호 없이

	//bp(); //함수 호출하듯이

	//void(*bp[3])(); //배열은 변수뒤에
	//bp[0] = Idle;
	//bp[1] = Move;
	//bp[2] = Attack;

	//int behavior;
	//cout << "행동 입력 : ";
	//cin >> behavior;
	////주소가 있는 모든애들은 포인터에 담을수 있다.

	//if (behavior == 0)
	//	Idle();
	//else if (behavior == 1)
	//	bp[1](); //무브랑 같은 느낌
	//else if (behavior == 2)
	//	Attack();

	//string result = Print("장현식"); //string Print(string name)
	//cout << result.c_str() << endl;

	//string(*sp)(string name); //string 포인터
	//sp = Print;

	//cout << sp("이름").c_str() << endl;

	//string str1 = "밥을";
	//string str2 = "먹자";
	//string result = str1 + str2; //연산자 오버로딩 플러스 기호가 숫자랑 쓰일때랑 다르다.
	//cout << result.c_str() << endl;

	//Callback
	void(*bp)() = Complete;

	Work(bp);
	cout << "==" << endl;
	Work(Idle);

	system("pause");
	return 0;
}