/*���� ���� 5���� �迭�� �����Ҵ� �ް�, ������ 5�� �Է¹޾�
����� ���ϰ� ����� �� �迭�� �Ҹ��Ű���� main()�Լ��� �ۼ��϶�.*/
#include <iostream>
using namespace std;

int main() {
	int* p = new int[5];
	int sum = 0;
	cout << "���� 5�� �Է�>> ";
	for (int i = 0; i < 5; i++)
		cin >> p[i];
	for (int i = 0; i < 5; i++)
		sum += p[i];
	cout << "��� : " << sum / 5.0;
}