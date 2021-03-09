/*c언어와 c++차이 함수지향 객체지향 C++은 클래스를 사용한다.
객체지향 c# 자바
객체지향 = 사람의 사고방식(주어, 동사)을 코드로 구현화 하고자 함
SetCusorConsolePosition(Handle,position)
객체지향의 경우 Cursor.Move() 주어가 바뀌는 느낌?
각 주어별로 모듈화 하여 낮은 결합도(Low Coupling), 높은 응집도(High Coheision)(플레이어한테 연관된 기능은 모두 플레이어가 갖고 있도록)를 갖도록 한다. 
각자의 독립성을 유지한다. 대규모 프로젝트에 적합. 각 담당별로 협업에 적합함. 사람의 실수를 최소화하기위해 존재 책임을 묻기 좋다.
클래스가 나오면서 C++ 업그레이드
*/
#include "stdafx.h"
//class와 struct의 차이 접근제어 public private 구조체는 퍼블릭 클래스는 프라이빗
class GameObject
{
private:
	float hp;
	float atk;

public:
	//Constructor 생성자 : 클래스 이름과 동일 보이드도 아니고 리턴도 없음
	//1)클래스의 이름과 동일해야함
	//2)타입이 없음
	//3)오버로딩 가능 여러개 만들수 있음
	GameObject()//기본생성자
	{
		//인스턴스화 변수로 올라갈때가 될때 호출됨 최초에 한번만 호출
		cout << "생성자가 호출됨" << endl;
		hp = 100;
		atk = 99;
	}
	GameObject(float hp, float atk)
	{
		cout << "변환 생성자가 호출됨" << endl;
		this->hp = hp;
		this->atk = atk;
	}

	GameObject(float hp)
	{
		cout << "변환 생성자2가 호출됨" << endl;
		this->hp = hp;
		this->atk = 0;
	}

	GameObject(const GameObject& obj)
	{
		cout << "복사 생성자가 호출됨" << endl;

		this->atk = obj.atk;
		this->hp = obj.hp;
	}

	//Setter
	void SetHp(float val) { /*this가 생략된거다*/hp = val; }
	void SetAtk(float atk) { /*이름이 겹쳐서 이건 쓴다*/this->atk = atk; }

	//Getter
	float GetAtk() { return atk; }
	float GetHp() { return hp; }

	void ShowStaus()
	{
		cout << "HP : " << hp << endl;
		cout << "Atk : " << atk << endl;
	}

	void WhatIsThis() { cout << this << endl; }


};//->캡슐화(정보의 은닉성)

struct Vector2
{
	short x, y;

	Vector2 operater(Vector2 vec)
	{
		return { x + vec.x, y + vec.y };
	}
};

int main()
{
	//연산자 오버로딩
	Vector2 vec1 = { 1,1 };
	Vector2 vec2 = { 3,1 };
	Vector2 result = vec1 + vec2;
	cout << result.x << " , " << result.y << endl;

	//Get, Set
	GameObject obj1; //여기서 생성자가 호출됨
	obj1.SetAtk(10);
	obj1.SetHp(50);
	obj1.ShowStaus();
	cout << "---------" << endl;
	cout << "obj1의 공격력 : " << obj1.GetAtk() << endl;

	//기본 생성자
	GameObject obj2;
	//obj2.SetAtk(100);
	//obj2.SetHp(100);
	cout << "----\n";
	obj2.ShowStaus();

	//기본 생성자2
	GameObject obj3;
	cout << "------\n";
	obj3.ShowStaus();
	
	//변환 생성자
	GameObject ob4(88, 88);
	ob4.ShowStaus();

	//변환 생성자2
	GameObject ob5(5);
	ob5.ShowStaus();

	//복사 생성자
	GameObject origin(10000, 10000);
	GameObject clone = origin; //대입연산자가 있을때 복사생성자가 호출됨
	clone.ShowStaus();

	//생성자, 소멸자

	system("pause");
	return 0;
}