#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	Point pos1;
	if (!pos1.InitMembers(-2, 4)) //Point.cpp에 따라 벗어난 범위의 값 전달 코드가 나오고 return false;라서 아래코드가 실행됨
		cout << "초기화 실패" << endl;
	if (!pos1.InitMembers(2, 4)) //x=xpos, y=ypos로 저장되고 return true; 라서 아래코드가 실행 안됨
		cout << "초기화 실패" << endl;

	Point pos2;
	if (!pos2.InitMembers(5, 9)) //저장되고 true라서 아래코드 실행 안됨
		cout << "초기화 실패" << endl;

	Rectangle rec;
	if (!rec.InitMembers(pos2, pos1)) //Rectangle.cpp에 따라서 pos2의 x축 값 또는 y축 값이 pos1보다 높아서 Rectangle.cpp의 코드가 실행되고 false라서 아래코드도 실행
		cout << "직사각형 초기화 실패" << endl;
	if (!rec.InitMembers(pos1, pos2)) //upLeft = ul, lowRight = lr; 로 저장되고 true라서 아래코드 실행 안됨
		cout << "직사각형 초기화 실패" << endl;

	rec.ShowReInfo(); //바로 위 코드에서 upLeft와 lowRight가 저장되어서 함수에 저장되어있는 코드가 출력
	return 0;
}