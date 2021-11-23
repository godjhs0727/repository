#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius = 0, string name=""):Circle(radius) {
		this->name = name;
	}
	void set(int radius, string name) {
		setRadius(radius);
		this->name = name;
	}
	string getName() { return name; }
};
int main(){
	int r, big = 0;
	string name;
	NamedCircle pizza[5];
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">>";
		cin >> r >> name;
		if (r <= 0) {
			cout << "�ٽ� �Է��ϼ���" << endl;
			i--;
			continue;
		}
		pizza[i].set(r, name);
		if (pizza[i].getArea() > pizza[big].getArea()) big = i;
	}
	cout << "���� ������ ū ���ڴ� " << pizza[big].getName() << "�Դϴ�" << endl;
	return 0;
}