#include <iostream>
using namespace std;

int main() {
	int ch, count = 0;
	while ((ch = cin.get()) != EOF) {
		if (ch == 'a') count++;
		else if (ch == '\n') break;
	}
	cout << "a °³¼ö : " << count << " °³" << endl;
}