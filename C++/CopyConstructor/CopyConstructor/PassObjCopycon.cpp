#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n)
	{}
	SoSimple(const SoSimple &copy) :num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple &copy)" << endl;
	}
	void ShowDate()
	{
		cout << "num: " << num << endl;
	}

};
void SimpleFunObj(SoSimple ob)
{
	ob.ShowDate();
}
int main()
{
	SoSimple obj(7); //num = 7 ����
	cout << "�Լ�ȣ�� ��" << endl;
	SimpleFunObj(obj); //��� ������ ���� 11���� ���� ����ǰ�, 17�� ����
	cout << "�Լ� ȣ�� ��" << endl;

	return 0;
}