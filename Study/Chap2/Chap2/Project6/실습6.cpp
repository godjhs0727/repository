#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char p1[100], p2[100];
	cout << "�� ��ȣ�� �Է��ϼ��� >>";
	cin >> p1;
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ��� >>";
	cin >> p2;
	if (strcmp(p1, p2) == 0)
		cout << "�����ϴ�";
	else
		cout << "���� �ʽ��ϴ�";
	return 0;
}