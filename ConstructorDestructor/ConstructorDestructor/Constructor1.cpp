#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass() //생성자
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n, int n2)
	{
		num1 = n;
		num2 = n2;
	}
	void ShowData()const
	{
		cout << num1 << ' ' << num2 << endl;
	}
	~SimpleClass() //소멸자
		
	{
		cout << "called destructor" << endl;
	}
};

int main()
{
	SimpleClass sc1;
	//SimpleClass sc4(); (X)
	SimpleClass * ptr1 = new SimpleClass; //(O)
	SimpleClass * ptr2 = new SimpleClass(); //(O)
	ptr1->ShowData();
	ptr2->ShowData();

	sc1.ShowData();

	SimpleClass sc2(100);
	SimpleClass *ptr = new SimpleClass(200); //동적할당의 형태
	ptr->ShowData();
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();

	delete ptr1;
	delete ptr2;
	delete ptr;

	return 0;
}