#include "stdafx.h"
#include <set>
#include <map>

//template<typename T1, typename T2>
//class Test
//{
//	T1 = name;
//	T2 = age;
//};

int main()
{
	//Test<int, float>; //이러면 name은 int로 들어가고 age는 float으로 들어가고
	
	//pair
	pair<string, UINT> person;
	person.first = "string type";
	person.second = 30;//UINT 타입
	cout << "이름 : " << person.first.c_str() << " 나이 : " << person.second << endl;

	pair<string, string> addressBook[3];
	addressBook[0] = { "김마린","서울시" };
	addressBook[1] = { "박질럿","부산시" };
	addressBook[2] = { "이드라","전주시" };

	for (int i = 0; i < ARRAYSIZE(addressBook); i++)
	{
		if (addressBook[i].first == "김마린")
			cout << addressBook[i].second.c_str() << endl;
	}


	//set
	set<int> set1 = { 5, 2, 4, 6, 1, 2 }; //vector도 중괄호 초기화가 가능하다
	for (int element : set1) //이건 배열형식으로 안됨
		cout << element << endl; //자동으로 오름차순이 적용되고 중복이 제거된다. 그치만 속도가 느리다.

	set<pair<string, int>> set2 = { {"B", 4}, {"E", 2}, {"A", 5}, {"D", 1}, {"B", 5} };
	for (auto&/*pair<string, int>이거랑 같다*/ i : set2)
		cout << i.first.c_str() << ", " << i.second << endl;

	//map : pair + set
	map<string, int> persons; //vector처럼 넣으면 계속 들어간다 가변길이
	persons["김마린"/*키값*/] = 10;
	persons["김마린"/*키값*/] = 20; //중복을 허용하지 않음 10이 20으로 덮어써짐
	cout << persons["김마린"] << endl;

	/*persons["오버로드"] = 20;*/
	persons.insert(make_pair("오버로드", 20));
	pair<string, int> zealot = { "질럿", 30 };
	persons.insert(zealot);

	for (auto& i : persons)
	{
		cout << i.first.c_str() << " : " << i.second << endl;
	}
	
	//iterator
	/*map<string, int>::iterator iter = persons.begin();
	for (iter; iter != persons.end(); iter++)
	{
		cout << *iter->first.c_str() << " : " << iter->second << endl;
	}*/

	cout << persons.count("김마린") << endl; //0 아니면 1이 나오는데 존재하기에 1이 나온다 존재 안하면 0

	map<string, int>::iterator iter = persons.find("질럿");
	cout << iter->second << endl;

	//enum Clip {Idle, Run, Attack, Jump};
	//map<Clip, UINT> clips; //우선순위 정할때 예를 들어


	system("pause");
	return 0;
}

/*
과제
위치
상점 벡터랑 인벤토리 벡터 2개 pushback을 통해서
구매 판매 장착
번호 이름 가격 공격력 방어력 재고
소지금 구매할 번호
구매 판매 팔때는 디스카운트?
장착하면 그에 맞는 공격력 등등이 적용
상점 클래스 인벤토리 클래스
인벤토리 예제 참조
상위 0번 누르면 함수 적용 if 로?
*/