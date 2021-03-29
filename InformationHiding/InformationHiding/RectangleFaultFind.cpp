#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	Point pos1;
	if (!pos1.InitMembers(-2, 4)) //Point.cpp�� ���� ��� ������ �� ���� �ڵ尡 ������ return false;�� �Ʒ��ڵ尡 �����
		cout << "�ʱ�ȭ ����" << endl;
	if (!pos1.InitMembers(2, 4)) //x=xpos, y=ypos�� ����ǰ� return true; �� �Ʒ��ڵ尡 ���� �ȵ�
		cout << "�ʱ�ȭ ����" << endl;

	Point pos2;
	if (!pos2.InitMembers(5, 9)) //����ǰ� true�� �Ʒ��ڵ� ���� �ȵ�
		cout << "�ʱ�ȭ ����" << endl;

	Rectangle rec;
	if (!rec.InitMembers(pos2, pos1)) //Rectangle.cpp�� ���� pos2�� x�� �� �Ǵ� y�� ���� pos1���� ���Ƽ� Rectangle.cpp�� �ڵ尡 ����ǰ� false�� �Ʒ��ڵ嵵 ����
		cout << "���簢�� �ʱ�ȭ ����" << endl;
	if (!rec.InitMembers(pos1, pos2)) //upLeft = ul, lowRight = lr; �� ����ǰ� true�� �Ʒ��ڵ� ���� �ȵ�
		cout << "���簢�� �ʱ�ȭ ����" << endl;

	rec.ShowReInfo(); //�ٷ� �� �ڵ忡�� upLeft�� lowRight�� ����Ǿ �Լ��� ����Ǿ��ִ� �ڵ尡 ���
	return 0;
}