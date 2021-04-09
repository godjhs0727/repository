#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase():baseNum(20) //20�� default ��
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() :derivNum(30) //������ 30 default��
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) :derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main()
{
	cout << "case1 . . . . " << endl;
	SoDerived dr1; //�θ� ���� ������, �ڽ� ���� : ���嵵 default������ 20, 30 ����
	dr1.ShowDerivData(); //���� ����� �� 20, 30 ������� ���
	cout << "case2 . . . . " << endl;
	SoDerived dr2(12);//�Ȱ��� �θ𳪿���, �ڽ��� ������� �־ �ٸ��� ������ �θ�� default�� 20�̰� �ڽ��� ����� ������� ����
	dr2.ShowDerivData(); //default 20��� �� 12���
	cout << "case3 . . . . " << endl;
	SoDerived dr3(24, 26); //�θ𳪿��� �ڽĳ����µ� ������� �θ�Ŭ������ ����Ǿ �տ��� �θ��� ������� �ڿ��� �ڽ� �������
	dr3.ShowDerivData(); //���� 24 ����� 26���
	return 0;
}