#include <iostream>
using namespace std;

class Point
{
public:
	int x; //x��ǥ�� ������ 0�̻� 100����
	int y; //���� ��
};

class Rectangle
{
public:
	Point upleft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "�� ���: " << '[' << upleft.x << ", ";
		cout << upleft.y << ']' << endl;
		cout << "�� �ϴ�: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl;
	}
};

int main()
{
	Point pos1 = { -2,4 };
	Point pos2 = { 5,9 };
	Rectangle rec = { pos1,pos2 };
	rec.ShowRecInfo();

	return 0;
}