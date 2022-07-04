#include <cstdinct>
#include <iostream>
using namespace std;

int main() {

	static_assert(sizeof(int) == 4, "int is 4bytes");
	int a = 0;
	cout << sizeof(int) << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(int8_t) << endl;
	cout << sizeof(int64_t) << endl;

	return 0;
}