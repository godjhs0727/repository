#include <iostream>
using namespace std;
#include "Password.h"

void PasswordManager::add()
{
	string name;
	string password;
	cout << "�̸� ��ȣ>> ";
	cin >> name >> password;
	passwordMap[name] = password; //key��, value��
}

void PasswordManager::search()
{
	string name;
	string inputPassword, storedPassword;
	cout << "�̸�? ";
	cin >> name;
	while (true) {
		cout << "��ȣ? ";
		cin >> inputPassword;
		storedPassword = passwordMap[name];
		if (inputPassword == storedPassword) { cout << "���!!" << endl; break; }
		else cout << "����~~" << endl;
	}
}
