#include <iostream>
using namespace std;

class Matrix{
	int a, b, c, d;
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a = a; this->b = b; this->c = c; this->d = d;
	}
	void show() {
		cout << "Matrix = { " << a << ' ' << b << ' ' << c << ' ' << d << " }" << endl;
	}
	Matrix operator+(Matrix b) {
		Matrix tmp;
		tmp.a = a + b.a;
		tmp.b = this->b + b.b;
		tmp.c = c + b.c;
		tmp.d = d + b.d;
		return tmp;
	}
	Matrix& operator+=(Matrix b) {
		a += b.a;
		this->b += b.b;
		c += b.c;
		d += b.d;
		return *this;
	}
	bool operator==(Matrix y) {
		if (a == y.a && b == y.b && c == y.c && d == y.d) return true;
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