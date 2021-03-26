#include <iostream>
#include <cstring>
using namespace std;

/*
����1
���� ����� Calculator Ŭ������ ������ ����. �⺻������ ���ϴ� ����� ����, ����, ����,
�׸��� �������̸�, ������ �� ������ ��� ������ ��� �����ߴ��� ��ϵǾ�� �Ѵ�. �Ʒ��� 
main�Լ��� ������ ���� �����ϴ� Calculator Ŭ������ �����ϸ� �ȴ�. ��, ��������� private����,
����Լ��� public���� ��������.
����2
���ڿ� ������ ���ο� �����ϴ� Printer��� �̸��� Ŭ������ ����������. �� Ŭ������ �ΰ��� ����� ������ ����.
-���ڿ� ����
-���ڿ� ���
�Ʒ��� main �Լ��� ������ ���� �����ϴ� Printer Ŭ������ �����ϵ�, �̹����� ���� ��������� private����,
����Լ��� public���� ��������.
*/
class Calculator
{
private:
	int add;
	int min;
	int mul;
	int div;
public:
	void Init()
	{
		add = 0;
		min = 0;
		mul = 0;
		div = 0;
	}
	double Add(double a, double b)
	{	
		add++;
		return a + b;
	}
	double Min(double a, double b)
	{
		min++;
		return a - b;
	}
	double Mul(double a, double b)
	{
		mul++;
		return a * b;
	}
	double Div(double a, double b)
	{
		div++;
		return a / b;
	}
	void ShowOpCount()
	{
		cout << "����: " << add << " ����: " << min << " ����: " << mul << " ������: " << div << endl;
	}
};

class Printer
{
private:
	char str[100];
public:
	void SetString(const char* str)
	{
		strcpy(this->str, str);
	}
	void ShowString()
	{
		cout << this->str << endl;
	}
};

int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	
	cout << endl;

	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}