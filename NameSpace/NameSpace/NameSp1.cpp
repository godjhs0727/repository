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
		cout << "ProgCom�� ������ �Լ�" << endl;
	}
}

int main()
{
	BestComImpl::SimpleFunc(); //���� ������ namespace�� ���� �Ŀ� ���ǵ� ����
	ProgComImpl::SimpleFunc();
	//���� �Լ� �̸��̾ �տ� namespace�� ���� �ٸ��� ���� ����
	return 0;
}

void BestComImpl::SimpleFunc()
{
	cout << "BestComImpl�� ������ �Լ�" << endl;
	PrettyFunc();//���� �̸�����
	ProgComImpl::SimpleFunc();//�ٸ� �̸�����
}

void BestComImpl::PrettyFunc()
{
	cout << "PrettyFunc" << endl;
}