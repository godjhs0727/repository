#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc();
}

namespace BestComImpl
{
	void PrettyFunc();
}

namespace ProgComImpl
{
	void SimpleFunc()
	{
		cout << "ProgCom이 정의한 함수" << endl;
	}
}

int main()
{
	BestComImpl::SimpleFunc(); //먼저 선언후 namespace를 통해 후에 정의도 가능
	ProgComImpl::SimpleFunc();
	//같은 함수 이름이어도 앞에 namespace에 따라서 다르게 구분 가능
	return 0;
}

void BestComImpl::SimpleFunc()
{
	cout << "BestComImpl이 정의한 함수" << endl;
	PrettyFunc();//동일 이름공간
	ProgComImpl::SimpleFunc();//다른 이름공간
}

void BestComImpl::PrettyFunc()
{
	cout << "PrettyFunc" << endl;
}