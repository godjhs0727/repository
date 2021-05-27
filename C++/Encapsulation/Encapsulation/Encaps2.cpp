#include <iostream>
using namespace std;

class SinivelCap //�๰ óġ�� ĸ��
{
public:
	void Take() const { cout << "�๰�� ��~ ���ϴ�." << endl; }
};

class SneezeCap //��ä�� óġ�� ĸ��
{
public:
	void Take() const { cout << "��ä�Ⱑ �ܽ��ϴ�." << endl; }
};

class SnuffleCap //�ڸ��� óġ�� ĸ��
{
public:
	void Take() const { cout << "�ڰ� ��~ �ո��ϴ�." << endl; } //��¿� const���ȭ
};

class CONTAC600 //�ѹ��� �� ����ִ� ��
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient //���� ĸ��ȭ�ؼ� ���������.
{
public:
	void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }
};

int main()
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);

	return 0;
}