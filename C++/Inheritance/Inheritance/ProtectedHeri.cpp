#include <iostream>
using namespace std;

class Base
{
private: //���� Ŭ���� �̿ܿ� ����������� ���� ���� ����.
	int num1;
protected: //��ӹ����������� ���� ���� �ִ�.
	int num2;
public: //��𼭵�
	int num3;

	Base() :num1(1),num2(2),num3(3){}
};
class Derived : public Base{}; //public���� ������Ǹ� �߱⿡ �ٱ����� ��� ����
//private����� �ǹ̾��� ����̰�, protected����� Derived�κ��� ��ӹ��� Ŭ������ ����� ����
int main()
{
	Derived drv;
	cout << drv.num3 << endl; //num3�� ��� ������ ������ num3�� Base���� public�̰�, num1�� private�� �ȵǰ� num2�� protected�� ��� ������������ ���� �ִ�.
	return 0;
}