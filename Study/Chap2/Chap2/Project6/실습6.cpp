#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char p1[100], p2[100];
	cout << "새 암호를 입력하세요 >>";
	cin >> p1;
	cout << "새 암호를 다시 한 번 입력하세요 >>";
	cin >> p2;
	if (strcmp(p1, p2) == 0)
		cout << "같습니다";
	else
		cout << "같지 않습니다";
	return 0;
}