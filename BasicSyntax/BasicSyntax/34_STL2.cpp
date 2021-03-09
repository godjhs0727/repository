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
	//Test<int, float>; //�̷��� name�� int�� ���� age�� float���� ����
	
	//pair
	pair<string, UINT> person;
	person.first = "string type";
	person.second = 30;//UINT Ÿ��
	cout << "�̸� : " << person.first.c_str() << " ���� : " << person.second << endl;

	pair<string, string> addressBook[3];
	addressBook[0] = { "�踶��","�����" };
	addressBook[1] = { "������","�λ��" };
	addressBook[2] = { "�̵��","���ֽ�" };

	for (int i = 0; i < ARRAYSIZE(addressBook); i++)
	{
		if (addressBook[i].first == "�踶��")
			cout << addressBook[i].second.c_str() << endl;
	}


	//set
	set<int> set1 = { 5, 2, 4, 6, 1, 2 }; //vector�� �߰�ȣ �ʱ�ȭ�� �����ϴ�
	for (int element : set1) //�̰� �迭�������� �ȵ�
		cout << element << endl; //�ڵ����� ���������� ����ǰ� �ߺ��� ���ŵȴ�. ��ġ�� �ӵ��� ������.

	set<pair<string, int>> set2 = { {"B", 4}, {"E", 2}, {"A", 5}, {"D", 1}, {"B", 5} };
	for (auto&/*pair<string, int>�̰Ŷ� ����*/ i : set2)
		cout << i.first.c_str() << ", " << i.second << endl;

	//map : pair + set
	map<string, int> persons; //vectoró�� ������ ��� ���� ��������
	persons["�踶��"/*Ű��*/] = 10;
	persons["�踶��"/*Ű��*/] = 20; //�ߺ��� ������� ���� 10�� 20���� �������
	cout << persons["�踶��"] << endl;

	/*persons["�����ε�"] = 20;*/
	persons.insert(make_pair("�����ε�", 20));
	pair<string, int> zealot = { "����", 30 };
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

	cout << persons.count("�踶��") << endl; //0 �ƴϸ� 1�� �����µ� �����ϱ⿡ 1�� ���´� ���� ���ϸ� 0

	map<string, int>::iterator iter = persons.find("����");
	cout << iter->second << endl;

	//enum Clip {Idle, Run, Attack, Jump};
	//map<Clip, UINT> clips; //�켱���� ���Ҷ� ���� ���


	system("pause");
	return 0;
}

/*
����
��ġ
���� ���Ͷ� �κ��丮 ���� 2�� pushback�� ���ؼ�
���� �Ǹ� ����
��ȣ �̸� ���� ���ݷ� ���� ���
������ ������ ��ȣ
���� �Ǹ� �ȶ��� ��ī��Ʈ?
�����ϸ� �׿� �´� ���ݷ� ����� ����
���� Ŭ���� �κ��丮 Ŭ����
�κ��丮 ���� ����
���� 0�� ������ �Լ� ���� if ��?
*/