#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt; //static 멤버로 같은 class내에서는 공유 접근이 가능함
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0; //초기화를 바깥에 하는 이유는 생성자 안에 초기화 하면 객체가 생성될때마다 0으로 초기화 된다.

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main()
{
	SoSimple sim1;
	SoSimple sim2;
	
	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();

	return 0;
}