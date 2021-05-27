#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n)
	{
		cout << "num=" << num << ", ";
		cout << "address=" << this << endl;
	}
	void ShowSimpleData() const
	{
		cout << num << endl;
	}
	SoSimple* GetThisPointer() //this ����
	{
		return this;
	}
};
int main()
{
	SoSimple sim(100);
	SoSimple *ptr1 = sim.GetThisPointer();
	cout << ptr1 << ", "; //adress�� ���
	ptr1->ShowSimpleData(); //num�� ���

	SoSimple sim2(200);
	SoSimple *ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	cout << endl;
	system("pause");
	return 0;
}