#include <iostream>
using namespace std;

class MyIntStack {
	int* p;
	int size;
	int tos;
public:
	MyIntStack() {
		size = 10;
		tos = 0;
		p = new int[size];
	}
	MyIntStack(int size) {
		this->size = size;
		tos = 0;
		p = new int[size];
	}
	MyIntStack(const MyIntStack& s) //복사생성자
	{
		size = s.size;
		tos = s.tos;
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = s.p[i];
	}
	~MyIntStack() {
		if (p)
			delete[] p;
	}
	bool push(int n) {
		if (tos == size)
			return false; //stack full
		p[tos] = n;
		tos++;
		return true;
	}
	bool pop(int& n) {
		if (tos == 0)
			return false; //stack empty
		tos--;
		n = p[tos];
		return true;
	}
};
int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}