//다음 main함수에서 필요로 하는 swap 함수를 오버로딩 해서 구현해보자
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(char*a, char*b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void swap(double* a, double* b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2); // Call By Adress
	swap(num1, num2); // Call By Reference
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2); // Call By Adress
	cout << ch1 << ' ' << ch2 << endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout << dbl1 << ' ' << dbl2 << endl;

}