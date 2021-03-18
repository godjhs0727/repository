#include <iostream>
using namespace std;

int main()
{
	int num = 10;
	int i = 0;

	cout << "true: " << true << endl;
	cout << "false: " << false << endl;

	while (true)
	{
		cout << i++ << ' ';
		if (i > num)
			break;
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;//int 크기 4byte
	cout << "sizeof 0: " << sizeof(0) << endl;//위와 동일
	cout << "sizeof true: " << sizeof(true) << endl;// bool 형 크기 1byte
	cout << "sizeof false: " << sizeof(false) << endl;//위와 동일

	return 0;
}