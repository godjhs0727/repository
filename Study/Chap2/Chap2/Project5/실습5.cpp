#include <iostream>
using namespace std;

int main() {
	char c[100];
	int count = 0;
	cout << "���ڵ��� �Է��϶�(100�� �̸�)." << endl;
	cin.getline(c, 100, '\n');//<Enter> Ű�� �Էµ� ������ ���� �б�

	int i = 0;
	while (true) {
		if (c[i] == '\0')break;
		if (c[i] == 'x')count++;
		i++;
	}
	cout << 'x' << "�� ������ " << count << endl;
}