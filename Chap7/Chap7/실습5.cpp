#include <iostream>
using namespace std;

class Color {
	int r, g, b;
public:
	Color(int r = 0, int g = 0, int b = 0) {
		this->r = r; this->g = g; this->b = b;
	}
	void show() {
		cout << "������ ���� : " << r << ' ' << "�ʷϻ� ���� : " << g << ' ' << "�Ķ��� ���� : " << b << endl;
	}
	Color operator+(Color blue) {
		Color tmp;
		tmp.r = r + blue.r;
		tmp.g = g + blue.g;
		tmp.b = b + blue.b;
		if (tmp.r >= 255)r = 255;
		if (tmp.g >= 255)g = 255;
		if (tmp.b >= 255)b = 255;
		return tmp;
	}
	bool operator==(Color purple) {
		if (r == purple.r && g == purple.g && b == purple.b) return true;
		else return false;
	}
};
int main() {
	Color red(255, 0, 0), blue(1, 0, 255), c;
	c = red + blue;		//red.+(blue) ȣ��
	c.show();			//�� �� ���

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) //c.==(fuchsia) ȣ��
		cout << "����� ����";
	else
		cout << "����� �ƴ�";
}