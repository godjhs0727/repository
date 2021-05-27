#include <iostream>
using namespace std;

int main()
{
	int num = 12;
	int *ptr = &num;
	int **dptr = &ptr;

	cout << num << endl; //num의 값
	cout << ptr << endl; //num의 주소 값, ptr의 값
	cout << dptr << endl; //ptr의 주소 값, dptr의 값

	int &ref = num; //num을 ref로
	int *(&pref) = ptr; //ptr을 pref로
	int **(&dpref) = dptr; //dptr을 dpref로

	cout << ref << endl;
	cout << pref << endl;
	cout << dpref << endl;

	return 0;
}