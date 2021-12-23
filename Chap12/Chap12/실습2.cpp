#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "열기 오류"; return 0;
	}
	string line;
	int lineno = 1;
	while (getline(fin, line)) {
		cout << lineno++ << " : " << line << endl;
	}
	fin.close();
	return 0;
}