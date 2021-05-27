#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex &copy) //복사생성자
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};

int main()
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex(); //임시객체

	return 0;
}
//simObjCnt는 SoSimple의 객체고, cmxObjCnt는 SoComplex의 객체이다 그러나 지금 두개 모두가 전역변수이기 때문에 어디서든 접근이 가능하므로
//이러한 제한을 지켜 줄만한 아무런 장치가 존재하지 않는다. 따라서 문제를 일으킬 소지가 매우 높기에 각각 전역변수를 각 클래스의 static멤버로
//선언하면 이 문제를 없앨 수 있다.