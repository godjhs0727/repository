#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	string text;
	srand((unsigned)time(0)); //������ ������, �ٸ� ������ �߻�seed����

	cout << "�Ʒ��� �� ���� �Է��ϼ���. (exit�� �Է��ϸ� �����մϴ�)" << endl;
	while (1) {
		cout << ">>";
		getline(cin, text);
		if (text == "exit")
			break;
		if (text == "")
			continue;
		int size = text.length();
		int index = rand() % size;
		int c = rand() % 26;
		char changeChar = 'a' + c;	//���� ������ ����
		if (text[index] == 'a' + c)changeChar = 'A' + c;
		text[index] == changeChar;
		cout << text << endl;
	}
}
