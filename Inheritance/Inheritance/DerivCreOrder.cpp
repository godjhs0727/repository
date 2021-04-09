#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase():baseNum(20) //20은 default 값
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() :derivNum(30) //생성자 30 default값
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) :derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main()
{
	cout << "case1 . . . . " << endl;
	SoDerived dr1; //부모 먼저 나오고, 자식 나옴 : 저장도 default값으로 20, 30 저장
	dr1.ShowDerivData(); //이제 저장된 값 20, 30 순서대로 출력
	cout << "case2 . . . . " << endl;
	SoDerived dr2(12);//똑같이 부모나오고, 자식은 멤버변수 있어서 다르게 나오고 부모는 default값 20이고 자식은 선언된 멤버변수 저장
	dr2.ShowDerivData(); //default 20출력 후 12출력
	cout << "case3 . . . . " << endl;
	SoDerived dr3(24, 26); //부모나오고 자식나오는데 멤버변수 부모클래스도 저장되어서 앞에는 부모의 멤버변수 뒤에는 자식 멤버변수
	dr3.ShowDerivData(); //따라서 24 출력후 26출력
	return 0;
}