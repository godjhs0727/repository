#include <iostream>
using namespace std;

int main()
{
	int num = 12;
	int *ptr = &num;
	int **dptr = &ptr;

	cout << num << endl; //num�� ��
	cout << ptr << endl; //num�� �ּ� ��, ptr�� ��
	cout << dptr << endl; //ptr�� �ּ� ��, dptr�� ��

	int &ref = num; //num�� ref��
	int *(&pref) = ptr; //ptr�� pref��
	int **(&dpref) = dptr; //dptr�� dpref��

	cout << ref << endl;
	cout << pref << endl;
	cout << dpref << endl;

	return 0;
}