/*
c++���� c����� ǥ���Լ� ȣ���ϱ�
c�� ���ϰ� .h�� ����
c++������ �Լ� �����ε��� �����ϱ� ������ �ڷ����� ���� �Լ��� �̸��� �޸��ؼ� �������� �ʰ�,
���� ����ϱ� ���ϵ��� �Լ��� �����ε� �� ���� ���̴�. �̷��� c++������ ������� ������ ���·�
���̺귯���� �����Ǿ� �����Ƿ�, ������ c++�� ǥ������� �̿��ؼ� �Լ��� ȣ���ϴ� ���� ����.
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

int main()
{
	char str1[] = "Result"; //string ��� ����
	char str2[30];

	strcpy(str2, str1); //str2�� "Result"�� ����ȴ�.
	printf("%s: %f \n", str1, sin(0.14)/*math��� ����(sin�ﰢ�Լ�)*/);
	printf("%s: %f \n", str2, abs(-1.25)/*abs�� ���밪*/);

	return 0;
}