#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos;	//스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() {
		tos = 0;
	}
	bool push(int n) {
		if (tos == 10)
			return false; //stack full
		p[tos] = n;
		tos++;
		return true;
	}
			//정수 n푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n) {
		if (tos == 0)
			return false; //stack empty
		tos--;
		n = p[tos];
		return true;
	}
			//팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
};

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {//11개를 푸시하면, 마지막에는 stack full이 된다.
		if (a.push(i)) cout << i << ' '; //푸시된 값 에코
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {//11개를 팝하면, 마지막에는 stack empty가 된다.
		if (a.pop(n)) cout << n << ' '; //팝된 값 에코
		else cout << endl << i + 1 << " 번째 stack empty" << endl;
	}
	return 0;
}