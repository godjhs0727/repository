#include <iostream>
using namespace std;

int Adder(int num1 = 1, int num2 = 2)
{
	return num1 + num2;
}
int main()
{
	cout << Adder() << endl; //아무것도 넣지 않았기에 Defalut값 1,2 적용
	cout << Adder(5) << endl; //5를 넣었기에 첫번째 매개변수만 5로 적용 나머지는 Default값 적용
	cout << Adder(3, 5) << endl;//3과 5를 넣었기에 첫번째와 두번째 매개변수 전부 변경


	return 0;
}