#include <iostream>
using namespace std;
int BoxVolume(int length, int width = 1, int height = 1);

int main()
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	//cout << "[D, D, D] : " << BoxVolume() << endl;
	//ù��°�� �Ű������� ���� �ٲ�� ����
	//�ι�°�� length�� width�� �ٲ�� �������� Default �� 1�� ����
	//����°�� length�� 7�� �ٲ�� ������ Default�� ����
	//�������� length�� Default���� ��� ������ ����!


	return 0;
}

int BoxVolume(int length, int width, int height)
{
	return length*width*height;
}
