#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value); //�Ű� ���� value �� ��� value�� �ʱ�ȭ�Ѵ�.
	Accumulator& add(int n); // value�� n�� ���� ���� �����Ѵ�.
	int get(); //������ �� value�� �����Ѵ�.
};

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); //acc�� value����� 28�� �ȴ�.
	cout << acc.get() << endl; //28���
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

	// TODO: ���⿡ return ���� �����մϴ�.
}

int Accumulator::get()
{
	return value;
}
