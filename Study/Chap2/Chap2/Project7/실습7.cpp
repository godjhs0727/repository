#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100];
	while (1) {
		cout << "�����ϰ� ������ yes�� �Է��ϼ���>>";
		cin.getline(str, 100, '\n');
		if (strcmp(str, "yes") == 0)
			break;
	}
	cout << "�����մϴ�" << endl;
}