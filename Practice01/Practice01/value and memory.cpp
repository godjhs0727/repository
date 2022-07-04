#include <iostream>
using namespace std;

int main() {
	int a = 0;
	int b = 3;
	int c = a + b;
	double d = 2.5;
	
	cout << "a: " << (long)&a << endl;
	cout << "b: " << (long)&b << endl;
	cout << "c: " << (long)&c << endl;
	cout << "d: " << (long)&d << endl;

	return 0;
}