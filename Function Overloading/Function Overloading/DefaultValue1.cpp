#include <iostream>
using namespace std;

int Adder(int num1 = 1, int num2 = 2)
{
	return num1 + num2;
}
int main()
{
	cout << Adder() << endl; //�ƹ��͵� ���� �ʾұ⿡ Defalut�� 1,2 ����
	cout << Adder(5) << endl; //5�� �־��⿡ ù��° �Ű������� 5�� ���� �������� Default�� ����
	cout << Adder(3, 5) << endl;//3�� 5�� �־��⿡ ù��°�� �ι�° �Ű����� ���� ����


	return 0;
}