#include <iostream>
#include <fstream>
using namespace std;

class FileCompare {
	ifstream src, dest;
public:
	FileCompare(const char* fsrc, const char* fdest);
	bool compare();
};

FileCompare::FileCompare(const char* fsrc, const char* fdest)
{
	src.open(fsrc, ios::in | ios::binary);
	if (!src) {
		cout << "�������"; exit(0);
	}
	dest.open(fdest, ios::in | ios::binary);
	if (!dest) {
		cout << "�������"; exit(0);
	}
}

bool FileCompare::compare()
{
	int s;
	while ((s = src.get()) != EOF) {		//�ҽ� ���Ͽ��� ���� ����Ʈ�� s
		int t = dest.get();					//���� ���Ͽ��� ���� ����Ʈ�� t
		// t�� s��						
		if (t == EOF) return false;			//���� ����
		else if (s != t) return false;		//���� ����
	}
	//�ҽ� ������ ������ �о���
	//���� ���Ͽ� ���� ���� ���Ҵ��� Ȯ��
	int t = dest.get();
	if (t != EOF) return false;
	//���� ���Ͽ��� ���� ���� �ִٸ� �� ������ ���� ����
	//both EOF
	return true;
}

int main() {
	cout << "���ϴ� �� ������" << "a.jpg" << "��"
		<< "b.jpg" << "�Դϴ�" << endl;
	cout << "�� �� ������ �ҽ� ������ �־�� �մϴ�" << endl;
	FileCompare comp("a.jpg", "b.jpg");
	//a.jpg�� b.jpg�� ��. �� ������ �ҽ� ������ �־�� ��
	if (comp.compare())
		cout << "�� ������ �����ϴ�" << endl;
	else
		cout << "�� ������ ���� �ʽ��ϴ�" << endl;
	return 0;
}