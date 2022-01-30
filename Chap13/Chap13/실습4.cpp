#include <iostream>
using namespace std;

int main() {
	int n;
	while (1) {
		cout << "��� �Է�>> ";
		try {
			cin >> n;			//failbit�� 1�� �µǾ� �ִ� ���,
			if (cin.fail())		//���˿� ���� �ʴ� �Է� �߻�
				throw "������ �ƴ� �� �Է�";
			if (n <= 0 || n > 9)
				throw n;
			for (int i = 1; i <= 9; i++) {
				cout << n << 'x' << i << '=' << n * i << ' ';
				cout << endl;
			}
		}
		catch (int e) {
			cout << "�߸��� �Է��Դϴ�. 1~9 ������ ������ �Է��ϼ���" << endl;
		}
		catch (const char* s) {
			cout << "�Է� ������ �߻��Ͽ� �� �̻� �Էµ��� �ʽ��ϴ�. ���α׷��� �����մϴ�" << endl;
			return 0;
		}
	}
	return 0;
}