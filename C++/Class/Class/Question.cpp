#include <iostream>
#include <cstring>
using namespace std;

/*
문제1
계산기 기능의 Calculator 클래스를 정의해 보자. 기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈,
그리고 나눗셈이며, 연산을 할 때마다 어떠한 연산을 몇번 수행했는지 기록되어야 한다. 아래의 
main함수와 실행의 예에 부합하는 Calculator 클래스를 정의하면 된다. 단, 멤버변수는 private으로,
멤버함수는 public으로 선언하자.
문제2
문자열 정보를 내부에 저장하는 Printer라는 이름의 클래스를 디자인하자. 이 클래스의 두가지 기능은 다음과 같다.
-문자열 저장
-문자열 출력
아래의 main 함수와 실행의 예에 부합하는 Printer 클래스를 정의하되, 이번에도 역시 멤버변수는 private으로,
멤버함수는 public으로 선언하자.
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
		cout << "덧셈: " << add << " 뺄셈: " << min << " 곱셈: " << mul << " 나눗셈: " << div << endl;
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