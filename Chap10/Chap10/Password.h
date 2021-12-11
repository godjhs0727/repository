#pragma once
#include <map>

class PasswordManager {
	string program;
	map<string, string> passwordMap;
public:
	PasswordManager(string program) { this->program = program; }
	string getProgram() { return program; }
	void add();
	void search();
};