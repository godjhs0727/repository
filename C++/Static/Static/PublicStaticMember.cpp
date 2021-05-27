#include <iostream>
using namespace std;

//static멤버변수의 또 다른 접근방법
//static멤버변수가 private로 선언되면, 해당 클래스의 객체들만 접근이 가능하지만, public으로 선언되면,
//클래스의 이름 또는 객체의 이름을 통해서 어디서든 접근이 가능하다.
class SoSimple
{
public:
	static int simObjCnt;
	/*static 멤버함수
	선언된 클래스의 모든 객체가 공유한다.
	public으로 선언되면, 클래스의 이름을 이용해서 호출이 가능하다.
	객체의 멤버로 존재하는 것이 아니다.
	static 멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다. const와 닮음
	*/
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;
int main()
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	//현재 SoSimple객체를 하나도 생성하지 않은 상태이다. 그럼에도 불구하고 클래스 이름을 통해서 simObjCnt에 접근하고 있다.
	SoSimple sim1;
	SoSimple sim2;
	
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
	//26,27행 : 생성한 객체 sim1과 sim2를 이용해서도 static멤버변수의 접근이 가능하지만 멤버변수에 접근하는 것과 같은 오해를 할수 있기 때문에 주의요망
	return 0;
}