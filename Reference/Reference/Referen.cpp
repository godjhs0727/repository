#include <iostream>
using namespace std;

int main()
{
	int num1 = 1020; //num1�� 1020���� ����
	int &num2 = num1; //������ &num2�� num1
	
	num2 = 3047; //num2�� �ٲ�⿡ num1�� �ٲ�
	cout << "Val: " << num1 << endl;
	cout << "Ref: " << num2 << endl; //�� 3047

	cout << "Val: " << &num1 << endl;
	cout << "Ref: " << &num2 << endl; //�ּҰ��� ����

	return 0;
}