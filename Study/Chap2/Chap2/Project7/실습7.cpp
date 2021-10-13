#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100];
	while (1) {
		cout << "종료하고 싶으면 yes를 입력하세요>>";
		cin.getline(str, 100, '\n');
		if (strcmp(str, "yes") == 0)
			break;
	}
	cout << "종료합니다" << endl;
}