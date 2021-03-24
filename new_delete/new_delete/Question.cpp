/*
구조체에 대한 복습을 겸할 수 있는 문제
2차원 평면상에서의 좌표를 표현할 수 있는
구조체를 다음과 같이 정의 하였다.
*/
#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;
/*
위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의 하고 (덧셈결과는 함수의
반환을 통해서 얻게 한다.)
*/
Point& pntAdder(const Point &p1, const Point &p2)
{
	Point*pptr = new Point; //new할당으로 정의
	pptr->xpos = p1.xpos + p2.xpos; //pptr의 xpos는 매개변수 p1,p2의 합
	pptr->ypos = p1.ypos + p2.ypos; //ypos는 위와 동
	return *pptr;
}

int main()
{
	Point *pptr = new Point;
	pptr->xpos = 3;
	pptr->ypos = 30;

	Point *pptr2 = new Point;
	pptr2->xpos = 70;
	pptr2->ypos = 7;

	Point &pref = pntAdder(*pptr, *pptr2); //참조자로 불러옴
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

	delete pptr; //Point*pptr에 대한 삭제
	delete pptr2; //Point*pptr2에 대한 삭제
	delete &pref; //함수 Point& pntAdder에 들어있는 new 할당에 대한 삭제


	return 0;
}

/*
임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의해보자. 단, 
*구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며, 
*할당된 메모리 공간의 소멸도 철저해야 한다. 
참고로 이 문제의 해결을 위해서는 다음 두 질문에 답을 할수 있어야 한다.
-동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가? (마침표 찍고 끌어온다.)
-함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?
*/
