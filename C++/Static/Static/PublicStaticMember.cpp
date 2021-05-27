#include <iostream>
using namespace std;

//static��������� �� �ٸ� ���ٹ��
//static��������� private�� ����Ǹ�, �ش� Ŭ������ ��ü�鸸 ������ ����������, public���� ����Ǹ�,
//Ŭ������ �̸� �Ǵ� ��ü�� �̸��� ���ؼ� ��𼭵� ������ �����ϴ�.
class SoSimple
{
public:
	static int simObjCnt;
	/*static ����Լ�
	����� Ŭ������ ��� ��ü�� �����Ѵ�.
	public���� ����Ǹ�, Ŭ������ �̸��� �̿��ؼ� ȣ���� �����ϴ�.
	��ü�� ����� �����ϴ� ���� �ƴϴ�.
	static ����Լ� �������� static ��������� static ����Լ��� ȣ���� �����ϴ�. const�� ����
	*/
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;
int main()
{
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	//���� SoSimple��ü�� �ϳ��� �������� ���� �����̴�. �׷����� �ұ��ϰ� Ŭ���� �̸��� ���ؼ� simObjCnt�� �����ϰ� �ִ�.
	SoSimple sim1;
	SoSimple sim2;
	
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;
	//26,27�� : ������ ��ü sim1�� sim2�� �̿��ؼ��� static��������� ������ ���������� ��������� �����ϴ� �Ͱ� ���� ���ظ� �Ҽ� �ֱ� ������ ���ǿ��
	return 0;
}