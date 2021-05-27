#include <iostream>
using namespace std;

class Point
{
public:
	int x; //x좌표의 범위는 0이상 100이하
	int y; //위와 동
};

class Rectangle
{
public:
	Point upleft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "좌 상단: " << '[' << upleft.x << ", ";
		cout << upleft.y << ']' << endl;
		cout << "우 하단: " << '[' << lowRight.x << ", ";
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