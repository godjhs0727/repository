#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n; i++)cout << v.at(i) << ' ';
	cout << endl;
}
double getAverage(vector<int>& v) {
	int sum = 0, n = v.size();
	for (int i = 0; i < n; i++) sum += v.at(i);
	return (double)sum / n;
}

int main() {
	vector<int> v;

	while (true) {
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
		int num;
		cin >> num;
		if (num == 0) return 0;		//���α׷� ����

		v.push_back(num);
		printVector(v);
		cout << "��� = " << getAverage(v) << endl;
	}

	return 0;
}