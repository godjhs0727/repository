#include <iostream>
using namespace std;

bool IsPositive(int num)
{
	if (num <= 0)
		return false;
	else
		return true;
}

int main()
{
	bool IsPos;
	int num;
	cout << "Input number: ";
	cin >> num;

	IsPos = IsPositive(num);
	if (IsPos) //bool형
		cout << "Positive number" << endl; //true 로 리턴
	else
		cout << "Negative number" << endl; //false


	return 0;
}