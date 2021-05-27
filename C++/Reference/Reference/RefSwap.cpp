#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
	cout << "교환후" << endl;
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main()
{
	int val1 = 10;
	int val2 = 20;

	cout << "교환전" << endl;
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;

	SwapByRef2(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;

	return 0;
}