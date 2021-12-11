#include <iostream>
using namespace std;
#include "Password.h"

int main() {
	int menu;
	PasswordManager mm("WHO");
	cout << "***** 암호관리 프로그램 " << mm.getProgram() << " 시작 *****" << endl;
	while (true) {
		cout << "삽입:1, 검사:2, 종료:3>> ";
		cin >> menu;
		switch (menu) {
		case 1: mm.add(); break;
		case 2: mm.search(); break;
		case 3: cout << "프로그램을 종료합니다..."; return 0;
		default: cout << "잘못된 선택이비다. 다시 선택해 주세요." << endl;
		}
		if (menu == 3) break;
	}
	return 0;
}