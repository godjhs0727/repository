/*String Ŭ������ �̿��Ͽ� ��ĭ�� �����ϴ� ���ڿ��� �Է¹ް� ���ڿ����� 'a'�� �� �� �ִ���
����ϴ� ���α׷��� �ۼ��غ���*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	cout << "���ڿ� �Է�>> ";
	getline(cin, text); //�� ĭ�� �����ϴ� ���ڿ� �� ���� �Է�

	int count = 0, index = 0;
	while (1) {
		index = text.find('a', index); //index���� 'a'ã��
		if (index = -1)
			break;
		count++;
		index++; //���� ã�� �ٷ� ���� ��ġ���� ã�� ����
	}
	cout << "���� a�� " << count << "�� �ֽ��ϴ�." << endl;
}