#include <iostream>
using namespace std;

int get() throw(const char*) {
	int num;
	cout << "0~9 �Է�>>";
	cin >> num;
	if (num < 0 || num>9) throw "input fault";
	else
		return num;
}

int main() {
	while (1) {
		int x, y;
		try {
			x = get();
			y = get();
			cout << x << 'x' << y << '=' << x * y << endl;
		}
		catch(const char* a){
			cout << a << " ���� �߻�, ����� �� ����" << endl;
		}
	}
}