#include <iostream>
using namespace std;
#include "Password.h"

void PasswordManager::add()
{
	string name;
	string password;
	cout << "이름 암호>> ";
	cin >> name >> password;
	passwordMap[name] = password; //key값, value값
}

void PasswordManager::search()
{
	string name;
	string inputPassword, storedPassword;
	cout << "이름? ";
	cin >> name;
	while (true) {
		cout << "암호? ";
		cin >> inputPassword;
		storedPassword = passwordMap[name];
		if (inputPassword == storedPassword) { cout << "통과!!" << endl; break; }
		else cout << "실패~~" << endl;
	}
}
