#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n)
	{}
	SoSimple(const SoSimple &copy) :num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple &copy)" << endl;
	}
	void ShowDate()
	{
		cout << "num: " << num << endl;
	}

};
void SimpleFunObj(SoSimple ob)
{
	ob.ShowDate();
}
int main()
{
	SoSimple obj(7); //num = 7 저장
	cout << "함수호출 전" << endl;
	SimpleFunObj(obj); //멤버 변수에 의해 11행이 먼저 실행되고, 17행 실행
	cout << "함수 호출 후" << endl;

	return 0;
}