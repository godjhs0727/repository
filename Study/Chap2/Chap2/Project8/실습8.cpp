#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100];
	char big[100];
	int length = 0;
	cout << "5명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";
	for (int i = 1; i <= 5; i++) {
		cin.getline(str, 100, ';');
		if (length < strlen(str)){		
			length = strlen(str);
			strcpy(big, str);
		}
		cout << i << " : " << str << endl;
	}
	cout << "가장 긴 이름은 " << big << endl;
}