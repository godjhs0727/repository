/*
����
const �����Ϳ� ���� ������ ���� �� �ִ� ����. ������ ��������� �غ���
const int num = 12;

������ ������ �����ؼ� �� ������ ����Ű�� �غ���. �׸��� �� ������ ������ �����ϴ� �����ڸ�
�ϳ� ��������. ���������� �̷��� ����� ������ ������ �����ڸ� �̿��ؼ� num�� ����� ����
����ϴ� ������ �ϼ��غ���.
*/
#include <iostream>
using namespace std;

int main()
{
	const int num = 12;
	const int *ptr = &num; //������ const int�̱⿡ �����͵� ������ const�� ���ȭ�Ѵ�.
	const int *(&ref) = ptr; //���� ���� ������ const�ϰ� �������̱⿡ �����ڰ�ȣ �� ������

	cout << *ptr << endl;
	cout << *ref << endl;


	return 0;
}