#include <iostream>
#include <string.h>//c��� ������� �߰�
#include <stdlib.h>//���� ��
using namespace std;

char *MakeStrAdr(int len)
{
	//char *str = (char*)malloc(sizeof(char)*len); //���ڿ� ������ ���� �迭�� �� ������ �Ҵ�
	char*str = new char[len];
	return str;
}

int main()
{
	char*str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	//free(str); //���� �Ҵ�� �޸� ������ �Ҹ�
	delete[]str;
	return 0;
}
/* ��������� �ִ�.
�Ҵ��� ����� ������ ������ ����Ʈ ũ������� �����ؾ� �Ѵ�.
��ȯ���� void�� �������̱� ������ ������ �� ��ȯ�� ���ľ� �Ѵ�.
*/
/*
c++���� �����ϴ� new�� delete�� ����ϸ� �����ϴ�.
int�� ������ �Ҵ�				int* ptr1 = new int;
double �� ���� �Ҵ�				double* ptr2 = new double;
���̰� 3�� int�� �迭�� �Ҵ�	int* arr1 = new int[3];
���̰� 7�� double �� �迭 �Ҵ�	double* arr2 = new double[7];

�ռ� �Ҵ��� ����, �迭 �Ҹ�
								delete ptr1;
								delete ptr2;
								delete []arr1;
								delete []arr2;
*/