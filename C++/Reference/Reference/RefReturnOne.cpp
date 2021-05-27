#include <iostream>
using namespace std;

int& RefRetFunOne(int &ref)
{
	ref++;
	return ref;
}

int main()
{
	int num1 = 1;
	int &num2 = RefRetFunOne(num1); //함수에 의해 이 순간 2로 증가
	num1++; // ++로 인해 2가 3으로 증가
	num2++; // 함수에 ++를 추가 하여 3에서 4증가
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	함
	return 0;
}