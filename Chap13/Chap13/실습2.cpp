#include <iostream>
using namespace std;

char grade(int score) throw(int){
	if (score < 0 || score>100) throw score;
	if (score < 60) return 'F';
	else if (score < 70) return 'D';
	else if (score < 80) return 'C';
	else if (score < 90) return 'B';
	else return 'A';
}

int main() {
	int score;
	while (1) {
		cout << "0~100 ������ ������ �Է��ϼ���>>";
		cin >> score;
		try {
			char c = grade(score);
			cout << c << "����" << endl;
		}
		catch (int s) {
			cout << s << ":���� �Է��� �߸��Ǿ����ϴ�." << endl;
		}
	}
}