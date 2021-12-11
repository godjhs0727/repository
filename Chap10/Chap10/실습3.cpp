#include <iostream>
using namespace std;

template <class T>

void reverseArray(T* a, int n) {
	for (int i = 0; i < n / 2; i++) {
		T temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
	return;
}
int main() {
	int x[] = { 1,10,100,5,4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++)cout << x[i] << ' ';
	cout << endl;

	int y[] = { -1,-10,-100,-1000 };
	reverseArray(y, 4);
	for (int i = 0; i < 4; i++)cout << y[i] << ' ';
	cout << endl;
	return 0;
}