#include <iostream>
using namespace std;

int main()
{
	int num1 = 1020; //num1을 1020으로 정의
	int &num2 = num1; //참조자 &num2가 num1
	
	num2 = 3047; //num2를 바꿨기에 num1도 바뀜
	cout << "Val: " << num1 << endl;
	cout << "Ref: " << num2 << endl; //값 3047

	cout << "Val: " << &num1 << endl;
	cout << "Ref: " << &num2 << endl; //주소값도 동일

	return 0;
}