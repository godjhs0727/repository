#include <iostream>
using namespace std;
#include "Password.h"

int main() {
	int menu;
	PasswordManager mm("WHO");
	cout << "***** ��ȣ���� ���α׷� " << mm.getProgram() << " ���� *****" << endl;
	while (true) {
		cout << "����:1, �˻�:2, ����:3>> ";
		cin >> menu;
		switch (menu) {
		case 1: mm.add(); break;
		case 2: mm.search(); break;
		case 3: cout << "���α׷��� �����մϴ�..."; return 0;
		default: cout << "�߸��� �����̺��. �ٽ� ������ �ּ���." << endl;
		}
		if (menu == 3) break;
	}
	return 0;
}