#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt; //static ����� ���� class�������� ���� ������ ������
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0; //�ʱ�ȭ�� �ٱ��� �ϴ� ������ ������ �ȿ� �ʱ�ȭ �ϸ� ��ü�� �����ɶ����� 0���� �ʱ�ȭ �ȴ�.

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main()
{
	SoSimple sim1;
	SoSimple sim2;
	
	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();

	return 0;
}