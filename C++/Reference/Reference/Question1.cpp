#include <iostream>
using namespace std;

/*
����1) �����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����Ͽ���.
���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�

�׸��� ���� �� �Լ��� ȣ���Ͽ� �� ����� Ȯ���ϴ� main �Լ����� �ۼ��Ͽ���

����2) �ռ� �Ұ��� ���� RefSwap.cpp �� SwapByRef2 �Լ��� ������ ���·� ȣ���ϸ� ������ ������ �߻��Ѵ�
SwapByRef2(23,45);
������ ������ �߻��ϴ� ������ �������� �����غ���

--���� : RefSwap.cpp�� SwapByRef2�� �Ű������� ������ int & �̱� ������ int�� ���ǵ� �Ű������� �ʿ��ϴ�.
23�� 45�� swap�ϴ� �Լ��� ����� ���� �Ʒ��� ����.
*/
/*
����3)
������ ���ÿ� �ռ� ���� ���� �ڵ带 ����.
int main()
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	. . .
}
���� �ڵ带 ���� ptr1�� ptr2�� ���� num1�� num2�� ����Ű�� �ִ�. �� �� ptr1�� ptr2�� ��
������ ������ ���� �Լ��� ȣ���ϰ� ����,
SwapPointer(ptr1,ptr2);
ptr1�� ptr2�� ����Ű�� ����� ���� �ٲ�� SwapPointer �Լ��� �����غ���.
*/

//����1)
void PlusOne(int &a)
{
	a = a + 1;
}
void Reverse(int &a)
{
	a = -a;

}
//����2)
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << a << ' ' << b << endl;
}
//����3)
void SwapPointer(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int n = 10;
	int num1 = 0;
	int num2 = 20;
	int *ptr1 = &num1;
	int *ptr2 = &num2;
	SwapPointer(ptr1, ptr2);

	PlusOne(n);
	Reverse(n);
	Swap(23, 45);
	cout << n << endl;
	cout << *ptr1 << ' ' << *ptr2 << endl;

	return 0;
}