#include <iostream>
using namespace std;

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

int main()
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;
	//AAA::BBB::CCC는 선언이 길어서 namespace를 이용하여 
	//ABC = AAA::BBB::CCC로 묶어서 간결화 시킬수 있다.
	return 0;
}