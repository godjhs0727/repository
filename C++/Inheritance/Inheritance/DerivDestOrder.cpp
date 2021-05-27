#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};
class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) :SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main()
{
	SoDerived drv1(15);
	SoDerived drv2(27);
	/*
	자식 클래스 소멸 후, 부모 클래스 소멸
	스택에 생성된 객체의 소멸순서는 생성순서와 반대
	생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제
	*/
	return 0;
}