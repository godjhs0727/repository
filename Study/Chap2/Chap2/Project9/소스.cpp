#include <iostream>
using namespace std;

class Oval {
	int width, height;
public:
	Oval();
	Oval(int w, int h);
	~Oval() {
		cout << "Oval ¼Ò¸ê : width " << width << ", height " << height << endl;
	}
	int getWidth() {
		return width;
	};
	int getHeight() {
		return height;
	};
	void set(int w, int h) {
		width = w;
		height = h;
	};
	void show() {
		cout << "width = " << width << ", height = " << height << endl;
	};
};
Oval::Oval() {
	width = height = 1;
}
Oval::Oval(int w, int h){
	width = w; 
	height = h;
}

int main()
{
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
	return 0;
}