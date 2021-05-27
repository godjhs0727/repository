#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{
	ref++;
	return ref;
}

int main()
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1); //함수로 현재 2가 되었다.

	num1 += 1; //2에 1을 더한다.
	num2 += 100; //num1은 3이 되었지만 정작 num2는 2그대로 이기에 102가 된다.
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}