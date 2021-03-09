#include "stdafx.h"

enum WeaponType { None, Sword, Gun, Axe, Spear }; //초록색은 커스텀 된 데이터 타입 //이미 있는것에서 선택하게 만드는게 enum 드롭박스 같은거

int main()
{
//	WeaponType type = Gun; //Gun은 2에 해당한다. 0, 1, 2, 3, 4
	typedef struct _Item //데이터 타입만 만들어 준거라 메모리에 안올라간다. 그저 설계
	{
		string name;
		WeaponType type;
		UINT atk;
		UINT price;

		void WhatIsThis()
		{
			cout << this << endl; //this에는 변수 주소가 들어간다.
		}
		
		string EnumToString()
		{
			string temp = "";

			switch (/*this->이게 생략되어 있다.*/type)
			{
				case None:	temp = "None";  break;
				case Sword:	temp = "Sword";  break; break;
				case Gun:	temp = "Gun";  break; break;
				case Axe:	temp = "Axe";  break; break;
				case Spear:	temp = "Spear";  break; break;
			}
			
			return temp;
		}

	} Item, _Item;//이걸로 하면 _Itme 대신에 그냥 Item으로 활용 가능 COORD흉내 f12로 검색

	cout << sizeof(WeaponType) << endl;//메모리가 얼마인지 모를때 sizeof로 확인 가능

	_Item sword;
	_Item spear = { "창", Spear, 20, 2000 };
	
	sword.name = "칼";
	sword.atk = 10;
	sword.type = Sword;
	sword.price = 1000;
	
	cout << "무기명 : " << sword.name.c_str() << endl; //스트링은 .c_str()해줘야 한다.
	cout << "공격력 : " << sword.atk << endl;
	cout << "타입 : " << sword.type << endl; //type 위치가 1에 있어서 1로 뜬다.
	cout << "가격 : " << sword.price << endl;
	cout << "-------------" << endl;
	cout << "무기명 : " << spear.name.c_str() << endl;
	cout << "공격력 : " << spear.atk << endl;
	cout << "타입 : " << spear.EnumToString().c_str() << endl; //위에랑 차이 확인해볼것
	cout << "가격 : " << spear.price << endl;

	//this
	sword.WhatIsThis();
	cout << &sword << endl;
	spear.WhatIsThis();
	cout << &spear << endl;

	//cout << sword.EnumToString().c_str() << endl;
	
	//구조체의 동적 할당
	Item* bullet = NULL; //주소만 저장되니깐 4바이트 그러나 new로 뚫어주면 40바이트
	char select;
	cout << "총알을 주울까? (y/n) : ";
	cin >> select;

	if (select == 'y')
	{
		bullet = new Item;
		bullet->name = "총알";
		bullet->atk = 100;
		bullet->price = 0;
		bullet->type = None;
		cout << bullet->name.c_str() << "을 주었다." << endl;
	}
	else
	{
		cout << "총알을 줍지 않았다." << endl;
	}
	if (bullet)
	{
		delete bullet; //safe delete 방식 그저 한줄로만 적는게 아니라, bullet이 발생한 후에 지워주는 방식 
		bullet = NULL;
	}

	Item bowArrow[2];
	bowArrow[0] = { "활", None, 10, 20 };
	bowArrow[1] = { "화살", None, 100, 20 };

	for (int i = 0; i < 2; i++)
		cout << bowArrow[i].name.c_str() << endl;

	//과제 짝맞추기 정답은 유지 시키고, 오답은 보였다가 사라지게
	//방법 구조체 이용 cls 유지시키기 랜덤으로 셔플로 짝 맞춰서 넣기 4x4로 하나만들고 테스트하고 하는 식으로 계속 해볼것
	//특수문자 큰따옴표 안에다가 저장 타입은 스트링타입으로

	system("pause");
	return 0;
}