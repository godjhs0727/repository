#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int main() {
	int s1[5];
	int s2[5];
	cout << "���� 5���� �Է��϶�. �迭 x�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++)
		cin >> s1[i];
	cout << "���� 5���� �Է��϶� �迭 y�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++)
		cin >> s2[i];
	int *p = ArrayUtility2::concat(s1, s2, 5);
	cout << "��ģ ���� �迭�� ����Ѵ�." << endl;
	for (int i = 0; i < 10; i++) cout << p[i] << ' ';
	cout << endl;

	int retSize;
	int* q = ArrayUtility2::remove(s1, s2, 5, retSize);
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << endl;
	for (int i = 0; i < retSize; i++) cout << q[i] << ' ';
	cout << endl;
	
	delete[] p;
	delete[] q;

	return 0;
}

int* ArrayUtility2::concat(int s1[], int s2[], int size)
{
	int* p = new int[size * 2];
	if (!p)
		return NULL;
	for (int i = 0; i < size; i++) 
		p[i] = s1[i];
	for (int i = 0; i < size; i++)
		p[i + size] = s2[i];
	return p;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize)
{
	int* p = new int[size];
	if (!p) { retSize = 0; return NULL; }
	retSize = 0;
	for (int i = 0; i < size; i++) {
		int j;
		for (j = 0; j < size; j++)
			if (s1[i] == s2[j]) break;
		if (j == size) {
			p[retSize] = s1[i];
			retSize++;
		}		
	}
	if (retSize == 0) return NULL;
	int* q = new int[retSize];
	if (!q) { retSize = 0; return NULL; }
	for (int i = 0; i < retSize; i++) q[i] = p[i];
	delete[] p;
	return q;
}
