//��1) ���� DefaultValue3.cpp�� ���ǵ� �Լ� BoxVolume�� '�Ű������� ����Ʈ �� ����'
//���°� �ƴ�, '�Լ� �����ε�'�� ���·� �� �����غ���. ���� main �Լ���
//�������� �ʾƾ� �ϸ�, �������� �����ؾ� �Ѵ�.

#include <iostream>
using namespace std;

int BoxVolume()
{
	return 0;
}
int BoxVolume(int length)
{
	return length;
}
int BoxVolume(int length, int width)
{
	return length * width;
}
int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}

int main()
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	cout << "[D, D, D] : " << BoxVolume() << endl;

	return 0;
}

//��2) ������ ���� ���·��� �Լ� �����ε��� ������ �ִ�.
//��� ������ �ִ��� �����غ���.
/*
int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}
*/
//���� Default ���� 10�� �ƴϰ� 11�� �ƴϰ� �ȴ�.