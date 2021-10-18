#include<iostream>
using namespace std;
class Circle {
	int radius; //원의 반지름 값
public:
	void setRadius(int radius); //반지름을 설정
	double getArea(); //면적을 리턴
};

void Circle::setRadius(int radius)
{	
	this->radius = radius;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main() {
	Circle c[3];
	int radius;
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i + 1 << "의 반지름>> ";
		cin >> radius;
		c[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (c[i].getArea() > 100)
			count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;
}