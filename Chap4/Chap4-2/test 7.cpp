#include<iostream>
using namespace std;
class Circle {
	int radius; //���� ������ ��
public:
	void setRadius(int radius); //�������� ����
	double getArea(); //������ ����
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
	Circle* c;
	int size;
	cout << "���� ����>> ";
	cin >> size; //���� ���� �Է�
	if (size < 1)return 0;
	c = new Circle[size]; //��ü �迭 ���� ����
	int radius;
	for (int i = 0; i < size; i++) {
		cout << "�� " << i + 1 << "�� ������>> ";
		cin >> radius;
		c[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (c[i].getArea() > 100)
			count++;
	}
	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�." << endl;
}