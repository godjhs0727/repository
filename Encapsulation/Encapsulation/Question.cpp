/*
다음의 Point 클래스를 기반으로 하여(활용하여) 원을 의미하는
Circle 클래스를 정의하자
*/
#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo()const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
/*
Circle 객체에는 좌표상의 위치 정보(원의 중심좌표)와 반지름의 길이 정보를 저장 및 출력할 수
있어야 한다. 그리고 여러분이 저의한 Circle 클래스를 기반으로 Ring 클래스도 정의하자. 링은
두 개의 원으로 표현 가능하무로 (바깥쪽 원과 안쪽 원), 두 개의 Circle 객체를 기반으로 정의가
가능하다. 참고로 안쪽 원과 바깥쪽 원의 중심좌표가 동일하다면 두께가 일정한 링을 표현하는 셈이
되며, 중심좌표가 동일하지 않다면 두께가 일정하지 않은 링을 표현하는 셈이 된다. 이렇게 해서
클래스의 정의가 완료되었다면, 다음 main 함수를 기반으로 실행을 시키자.
*/

class Circle
{
private:
	int rad; //반지름
	Point center; //원의 중심
public:
	void Init(int x, int y, int r)
	{
		rad = r;
		center.Init(x, y);
	}

	void ShowCircleInfo() const
	{
		cout << "radius : " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inCircle;
	Circle outCircle;
public:
	void Init(int inX, int inY, int inR, int outX, int outY, int outR)
	{
		inCircle.Init(inX, inY, inR);
		outCircle.Init(outX, outY, outR);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		inCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outCircle.ShowCircleInfo();
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}
/*
Init의 함수호출을 통해서 전달된 1, 1, 4는 안쪽 원의 정보에 해당하며 (순서대로 X좌표, Y좌표,
반지름), 이어서 전달된 2, 2, 9는 바깥쪽 원의 정보에 해당한다(순서대로 X좌표, Y좌표, 반지름),
그리고 실행결과는 다음과 같거나 유사해야 한다.
실행결과)
Inner Circle Info...
radius:4
[1, 1]
Outter Circle Info...
radius:9
[2, 2]
*/