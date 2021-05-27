#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2) //this포인터가 없다면 이름이 동일하여 멤버변수만 인식하여 지역변수를 불러올수 없다.
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	/*
	TwoNumber(int num1, int num2)
		:num1(num1), num2(num2){}
		이니셜라이저를 이용해도 가능
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main()
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	
	return 0;
}