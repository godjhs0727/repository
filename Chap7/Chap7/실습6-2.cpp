#include <iostream>
using namespace std;

class Matrix {
	int a, b, c, d;
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a = a; this->b = b; this->c = c; this->d = d;
	}
	void show() {
		cout << "Matrix = { " << a << ' ' << b << ' ' << c << ' ' << d << " }" << endl;
	}
	friend Matrix operator+(Matrix x, Matrix b) {
		Matrix tmp;
		tmp.a = x.a + b.a;
		tmp.b = x.b + b.b;
		tmp.c = x.c + b.c;
		tmp.d = x.d + b.d;
		return tmp;
	}
	friend Matrix& operator+=(Matrix &x, Matrix b) {
		x.a += b.a;
		x.b += b.b;
		x.c += b.c;
		x.d += b.d;
		return x;
	}
	friend bool operator==(Matrix x, Matrix y) {
		if (x.a == y.a && x.b == y.b && x.c == y.c && x.d == y.d) return true;
		else return false;
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