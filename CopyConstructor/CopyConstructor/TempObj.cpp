#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n):num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main()
{
	Temporary(100); //임시객체 생성
	cout << "after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "after make!" << endl << endl;

	const Temporary &ref = Temporary(300); //위와 다르게 참조자로 임시객체 참조하기때문에 소멸자 마지막에
	cout << "end of main" << endl << endl;

	return 0;
}