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
	int num2 = RefRetFuncOne(num1); //�Լ��� ���� 2�� �Ǿ���.

	num1 += 1; //2�� 1�� ���Ѵ�.
	num2 += 100; //num1�� 3�� �Ǿ����� ���� num2�� 2�״�� �̱⿡ 102�� �ȴ�.
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}