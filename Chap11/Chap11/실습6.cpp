#include <iostream>
using namespace std;

class Circle {
	string name; int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	friend ostream& operator <<(ostream& outs, Circle c);
	friend istream& operator >>(istream& ins, Circle c);
};

int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
	return 0;
}

ostream& operator<<(ostream& outs, Circle c)
{
	outs << "반지름이 " << c.radius << "인 " << c.name << endl;
	return outs;
}

istream& operator>>(istream& ins, Circle c)
{
	cout << "반지름 >> ";
	ins >> c.radius;
	cout << "이름 >> ";
	ins >> c.name;
	return ins;
}
