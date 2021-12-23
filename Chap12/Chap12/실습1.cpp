#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\Temp\\test.txt");
	if (!fin) {
		cout << "파일 열기 실패!!!" << endl;
		return 0;
	}
	int ch;
	while ((ch = fin.get()) != EOF)
		cout.put(ch);
	fin.close();
	return 0;
}