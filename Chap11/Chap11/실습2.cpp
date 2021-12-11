#include <iostream>
using namespace std;

int main() {
	char ch;
	int count = 0;
	while (true) {
		cin.get(ch);
		if (cin.eof()) break;
		else if (ch == ' ') count++;
		else if (ch == '\n') break;
	}
	cout << "a °³¼ö : " << count << " °³" << endl;
}