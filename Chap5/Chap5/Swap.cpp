#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void swap(Circle& a, Circle& b) {
	Circle temp = a;
	a = b;
	b = temp;
}

int main(){
	Circle a, b(10);
	cout << "a�� ���� : " << a.getArea() << ", " << "b�� ���� : " << b.getArea() << endl;
	swap(a, b);
	cout << "a�� ���� : " << a.getArea() << ", " << "b�� ���� : " << b.getArea() << endl;
	return 0;
}