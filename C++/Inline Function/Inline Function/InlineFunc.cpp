#include <iostream>
using namespace std;
template <typename T>
inline T square(T x)
{
	return x * x;
}

//��ũ�ο� ��
#define Square(x) ((x)*(x)) //��ũ�δ� �ڷ����� �������� �ʴ´�.

inline int SQUARE(int x) //inline �� �ڷ����� �����δ� template �� ����ؼ� ������ �ս��� ���´�.
{
	return x * x;
}
int main()
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(12) << endl << endl;
	cout << Square(6) << endl;
	cout << Square(3.14) << endl << endl;
	cout << square(5) << endl;
	cout << square(3.14) << endl;


	return 0;
}