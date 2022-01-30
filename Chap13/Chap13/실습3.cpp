#include <iostream>
using namespace std;

int get() throw(const char*) {
	int num;
	cout << "0~9 입력>>";
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
			cout << a << " 예외 발생, 계산할 수 없음" << endl;
		}
	}
}