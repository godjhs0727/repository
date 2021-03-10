#include <iostream>
using namespace std;
int main()
{
	int val;
	cout << "숫자 입력 : ";
	cin >> val;
	
	int val2;
	cout << "두번째 숫자 입력 : ";
	cin >> val2;

	int result = val + val2;
	cout << "덧셈 결과 : " << result << endl;
	return 0;
}