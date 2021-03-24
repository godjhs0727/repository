/*
����1
���� ǥ���Լ��� ȣ���ϴ� ������ �����, c++�� ����� �����ؼ� ������. �׸��� ������ ������
���������, �Ʒ��� �Լ����� �ּ� 1ȸ �̻� ȣ���ؾ� �Ѵ�. ����� ���� �Լ����� C����� ���
<string.h>�� ����Ǿ� �ִ�.
-strlen ���ڿ��� ���� ���
-strcat ���ڿ��� �ڿ� �����̱�
-strcpy ���ڿ� ����
-strcmp ���ڿ� ��

����2
���� �� �Լ��� �̿��ؼ� 0�̻� 100�̸��� ������ �� 5�� �����ϴ� ������ �����, c++�� �����
�����ؼ� �ۼ��غ���, ����� c����� ��� time �Լ��� <time.h>�� ����Ǿ� �ְ�, rand�Լ���
srand�Լ��� <stdlib.h>�� ����Ǿ� �ִ�.
rand, srand, time
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//����1
	const char *str1 = "ABC 123 ";
	const char *str2 = "DEF 456 ";
	char str3[50];
	cout << strlen(str1) << endl; //���ڱ��� ������� �����Ͽ� 8
	cout << strlen(str2) << endl;
	strcpy(str3, str1); //���縦 �ߴ� ���� str3�� ����
	strcat(str3, str2); //str3 �ڿ� str2�� ���δ�.
	cout << str3 << endl;

	if (strcmp(str1, str2) == 0) //���� ���ڿ��� ������ ������ �� (���� �ϳ��ϳ�)
		cout << "���ڿ��� ����." << endl;
	else
		cout << "���ڿ��� ���� �ʴ�." << endl;

	//����2
	srand(time(NULL)); //time�Լ��� ������ ����� �ִ�
	for (int i = 0; i < 5; i++)
	{
		printf("Random number #%d: %d\n", i, rand() % 100/*0�̻� 100�̸��� ������ ����⿡ mod�Լ��� ������ 0~99���ڰ� �����⿡ rand() % 100*/);
	}

	return 0;
}