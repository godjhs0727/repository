#include <iostream>
using namespace std;

template <class T>

bool search(T a, T* b, int c) {
	for (int i = 0; i < c; i++) {
		if (a == b[i]) return true;
	}
	return false;
}
int main() {
	int x[] = { 1,10,100,5,4 };
	if (search(100, x, 5)) cout << "100�� �迭 x�� ���ԵǾ� �ִ�.";
	else
		cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�.";
	cout << endl;

	char c[] = { 'h','e','l','l','o' };
	if (search('e', c, 5)) cout << "e�� �迭 c�� ���ԵǾ� �ִ�.";
	else
		cout << "e�� �迭 c�� ���ԵǾ� ���� �ʴ�.";
	cout << endl;
	return 0;
}