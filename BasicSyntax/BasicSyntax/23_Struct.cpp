#include "stdafx.h"

enum WeaponType { None, Sword, Gun, Axe, Spear }; //�ʷϻ��� Ŀ���� �� ������ Ÿ�� //�̹� �ִ°Ϳ��� �����ϰ� ����°� enum ��ӹڽ� ������

int main()
{
//	WeaponType type = Gun; //Gun�� 2�� �ش��Ѵ�. 0, 1, 2, 3, 4
	typedef struct _Item //������ Ÿ�Ը� ����� �ذŶ� �޸𸮿� �ȿö󰣴�. ���� ����
	{
		string name;
		WeaponType type;
		UINT atk;
		UINT price;

		void WhatIsThis()
		{
			cout << this << endl; //this���� ���� �ּҰ� ����.
		}
		
		string EnumToString()
		{
			string temp = "";

			switch (/*this->�̰� �����Ǿ� �ִ�.*/type)
			{
				case None:	temp = "None";  break;
				case Sword:	temp = "Sword";  break; break;
				case Gun:	temp = "Gun";  break; break;
				case Axe:	temp = "Axe";  break; break;
				case Spear:	temp = "Spear";  break; break;
			}
			
			return temp;
		}

	} Item, _Item;//�̰ɷ� �ϸ� _Itme ��ſ� �׳� Item���� Ȱ�� ���� COORD�䳻 f12�� �˻�

	cout << sizeof(WeaponType) << endl;//�޸𸮰� ������ �𸦶� sizeof�� Ȯ�� ����

	_Item sword;
	_Item spear = { "â", Spear, 20, 2000 };
	
	sword.name = "Į";
	sword.atk = 10;
	sword.type = Sword;
	sword.price = 1000;
	
	cout << "����� : " << sword.name.c_str() << endl; //��Ʈ���� .c_str()����� �Ѵ�.
	cout << "���ݷ� : " << sword.atk << endl;
	cout << "Ÿ�� : " << sword.type << endl; //type ��ġ�� 1�� �־ 1�� ���.
	cout << "���� : " << sword.price << endl;
	cout << "-------------" << endl;
	cout << "����� : " << spear.name.c_str() << endl;
	cout << "���ݷ� : " << spear.atk << endl;
	cout << "Ÿ�� : " << spear.EnumToString().c_str() << endl; //������ ���� Ȯ���غ���
	cout << "���� : " << spear.price << endl;

	//this
	sword.WhatIsThis();
	cout << &sword << endl;
	spear.WhatIsThis();
	cout << &spear << endl;

	//cout << sword.EnumToString().c_str() << endl;
	
	//����ü�� ���� �Ҵ�
	Item* bullet = NULL; //�ּҸ� ����Ǵϱ� 4����Ʈ �׷��� new�� �վ��ָ� 40����Ʈ
	char select;
	cout << "�Ѿ��� �ֿ��? (y/n) : ";
	cin >> select;

	if (select == 'y')
	{
		bullet = new Item;
		bullet->name = "�Ѿ�";
		bullet->atk = 100;
		bullet->price = 0;
		bullet->type = None;
		cout << bullet->name.c_str() << "�� �־���." << endl;
	}
	else
	{
		cout << "�Ѿ��� ���� �ʾҴ�." << endl;
	}
	if (bullet)
	{
		delete bullet; //safe delete ��� ���� ���ٷθ� ���°� �ƴ϶�, bullet�� �߻��� �Ŀ� �����ִ� ��� 
		bullet = NULL;
	}

	Item bowArrow[2];
	bowArrow[0] = { "Ȱ", None, 10, 20 };
	bowArrow[1] = { "ȭ��", None, 100, 20 };

	for (int i = 0; i < 2; i++)
		cout << bowArrow[i].name.c_str() << endl;

	//���� ¦���߱� ������ ���� ��Ű��, ������ �����ٰ� �������
	//��� ����ü �̿� cls ������Ű�� �������� ���÷� ¦ ���缭 �ֱ� 4x4�� �ϳ������ �׽�Ʈ�ϰ� �ϴ� ������ ��� �غ���
	//Ư������ ū����ǥ �ȿ��ٰ� ���� Ÿ���� ��Ʈ��Ÿ������

	system("pause");
	return 0;
}