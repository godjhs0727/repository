#include <iostream>
using namespace std;

namespace Hybrid
{
	void HybFunc()
	{
		cout << "So Simple function!" << endl;
		cout << "In namespace Hybrid!" << endl;
	}
}
int main()
{
	using Hybrid::HybFunc;
	//Ű���� using�� �̿��ؼ� '�̸����� Hybrid�� ���ǵ� HyFunc�� ȣ���� ������,
	//�̸� ������ �������� �ʰ� ȣ���ϰڴ�!'�� ���� ���(����)�ϰ� �ִ�.
	HybFunc();
	//�̸����� �������� using�������� HybFunc�Լ� ȣ��

	/*
	cout, cin, endl �� �����Ҷ� ������ std::cout �̷������� ���־���ϴµ�
	using�� ���Ͽ� using std::cout; �� �ϰ� �Ǹ� cout�� std::cout�� �����
	�ʿ䰡 �������� using namespace std;�� �ϰ� �Ǹ� std::�� ���� ������
	std::�� �ʿ�������� �ȴ�.
	*/

	return 0;
}