#include <iostream>
using namespace std;

int RefRetFunTwo(int &ref) //��ȯ���� �⺻�ڷ��� int�̴�.
{
	ref++;
	return ref;
}

int main()
{
	int num1 = 1;
	int num2 = RefRetFunTwo(num1);
	//�����ڸ� ��ȯ������, ��ȯ���� �⺻�ڷ��� int�̱� ������ �����ڰ� �����ϴ� ������ ����
	//��ȯ�ȴ�. �ٽ� �ѹ� ��������, ������ ����� ���� ��ȯ�ȴ�.

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	return 0;
}