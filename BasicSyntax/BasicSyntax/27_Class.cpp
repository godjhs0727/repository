/*c���� c++���� �Լ����� ��ü���� C++�� Ŭ������ ����Ѵ�.
��ü���� c# �ڹ�
��ü���� = ����� �����(�־�, ����)�� �ڵ�� ����ȭ �ϰ��� ��
SetCusorConsolePosition(Handle,position)
��ü������ ��� Cursor.Move() �־ �ٲ�� ����?
�� �־�� ���ȭ �Ͽ� ���� ���յ�(Low Coupling), ���� ������(High Coheision)(�÷��̾����� ������ ����� ��� �÷��̾ ���� �ֵ���)�� ������ �Ѵ�. 
������ �������� �����Ѵ�. ��Ը� ������Ʈ�� ����. �� ��纰�� ������ ������. ����� �Ǽ��� �ּ�ȭ�ϱ����� ���� å���� ���� ����.
Ŭ������ �����鼭 C++ ���׷��̵�
*/
#include "stdafx.h"
//class�� struct�� ���� �������� public private ����ü�� �ۺ� Ŭ������ �����̺�
class GameObject
{
private:
	float hp;
	float atk;

public:
	//Constructor ������ : Ŭ���� �̸��� ���� ���̵嵵 �ƴϰ� ���ϵ� ����
	//1)Ŭ������ �̸��� �����ؾ���
	//2)Ÿ���� ����
	//3)�����ε� ���� ������ ����� ����
	GameObject()//�⺻������
	{
		//�ν��Ͻ�ȭ ������ �ö󰥶��� �ɶ� ȣ��� ���ʿ� �ѹ��� ȣ��
		cout << "�����ڰ� ȣ���" << endl;
		hp = 100;
		atk = 99;
	}
	GameObject(float hp, float atk)
	{
		cout << "��ȯ �����ڰ� ȣ���" << endl;
		this->hp = hp;
		this->atk = atk;
	}

	GameObject(float hp)
	{
		cout << "��ȯ ������2�� ȣ���" << endl;
		this->hp = hp;
		this->atk = 0;
	}

	GameObject(const GameObject& obj)
	{
		cout << "���� �����ڰ� ȣ���" << endl;

		this->atk = obj.atk;
		this->hp = obj.hp;
	}

	//Setter
	void SetHp(float val) { /*this�� �����ȰŴ�*/hp = val; }
	void SetAtk(float atk) { /*�̸��� ���ļ� �̰� ����*/this->atk = atk; }

	//Getter
	float GetAtk() { return atk; }
	float GetHp() { return hp; }

	void ShowStaus()
	{
		cout << "HP : " << hp << endl;
		cout << "Atk : " << atk << endl;
	}

	void WhatIsThis() { cout << this << endl; }


};//->ĸ��ȭ(������ ���м�)

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
	//������ �����ε�
	Vector2 vec1 = { 1,1 };
	Vector2 vec2 = { 3,1 };
	Vector2 result = vec1 + vec2;
	cout << result.x << " , " << result.y << endl;

	//Get, Set
	GameObject obj1; //���⼭ �����ڰ� ȣ���
	obj1.SetAtk(10);
	obj1.SetHp(50);
	obj1.ShowStaus();
	cout << "---------" << endl;
	cout << "obj1�� ���ݷ� : " << obj1.GetAtk() << endl;

	//�⺻ ������
	GameObject obj2;
	//obj2.SetAtk(100);
	//obj2.SetHp(100);
	cout << "----\n";
	obj2.ShowStaus();

	//�⺻ ������2
	GameObject obj3;
	cout << "------\n";
	obj3.ShowStaus();
	
	//��ȯ ������
	GameObject ob4(88, 88);
	ob4.ShowStaus();

	//��ȯ ������2
	GameObject ob5(5);
	ob5.ShowStaus();

	//���� ������
	GameObject origin(10000, 10000);
	GameObject clone = origin; //���Կ����ڰ� ������ ��������ڰ� ȣ���
	clone.ShowStaus();

	//������, �Ҹ���

	system("pause");
	return 0;
}