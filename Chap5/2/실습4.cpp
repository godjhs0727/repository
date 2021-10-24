#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b)
		return true;
	else if (a > b) {
		big = a;
		return false;
	}
	else
	{
		big = b;
		return false;
	}
}

int main() {
	int a, b, big;
	bool c;
	cout << "정수를 입력하시오 : ";
	cin >> a >> b;
	c = bigger(a, b, big);
	if (c)
		cout << "same" << endl;
	else
		cout << big << endl;
	return 0;
}