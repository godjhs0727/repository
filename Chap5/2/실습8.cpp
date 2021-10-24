#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value); //매개 변수 value 로 멤버 value를 초기화한다.
	Accumulator& add(int n); // value에 n을 더해 값을 누적한다.
	int get(); //누적된 값 value를 리턴한다.
};

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); //acc의 value멤버가 28이 된다.
	cout << acc.get() << endl; //28출력
	return 0;
}

Accumulator::Accumulator(int value)
{
	this->value = value;
}

Accumulator& Accumulator::add(int n)
{
	this->value += n;
	return *this;

	// TODO: 여기에 return 문을 삽입합니다.
}

int Accumulator::get()
{
	return value;
}
