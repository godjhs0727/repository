#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100];
	char big[100];
	int length = 0;
	cout << "5���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << endl << ">>";
	for (int i = 1; i <= 5; i++) {
		cin.getline(str, 100, ';');
		if (length < strlen(str)){		
			length = strlen(str);
			strcpy(big, str);
		}
		cout << i << " : " << str << endl;
	}
	cout << "���� �� �̸��� " << big << endl;
}