#include <iostream>
using namespace std;

class Matrix {
	int ar[4];
public:
	Matrix(){
		for (int i = 0; i < 4; i++)ar[i] = 0;
	}
	Matrix(int a, int b, int c, int d) {
		ar[0] = a;
		ar[1] = b;
		ar[2] = c;
		ar[3] = d;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++)cout << ar[i] << ' ';
		cout << "}" << endl;
	}
	Matrix operator+(Matrix b) {
		Matrix tmp;
		for (int i = 0; i < 4; i++) {
			tmp.ar[i] = ar[i] + b.ar[i];
		}
		return tmp;
	}
	Matrix& operator+=(Matrix b) {
		for (int i = 0; i < 4; i++) {
			ar[i] += b.ar[i];
		}
		return *this;
	}
	bool operator==(Matrix y) {
		for (int i = 0; i < 4; i++) {
			if (ar[i] == y.ar[i])return true;
			else return false;
		}
	}
};
int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
	return 0;
}