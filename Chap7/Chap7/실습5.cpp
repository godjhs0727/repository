#include <iostream>
using namespace std;

class Color {
	int r, g, b;
public:
	Color(int r = 0, int g = 0, int b = 0) {
		this->r = r; this->g = g; this->b = b;
	}
	void show() {
		cout << "빨간색 성분 : " << r << ' ' << "초록색 성분 : " << g << ' ' << "파란색 성분 : " << b << endl;
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
	c = red + blue;		//red.+(blue) 호출
	c.show();			//색 값 출력

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) //c.==(fuchsia) 호출
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}