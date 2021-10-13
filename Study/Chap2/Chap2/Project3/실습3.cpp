#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cout << "두 수를 입력하라 >>";
	cin >> x >> y;
	cout << "큰 수 = ";
	z = x > y ? x : y;
	cout << z;


	return 0;
}