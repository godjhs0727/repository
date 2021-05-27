#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		:num1(n1),num2(n2){}
	/*explicit�� �տ� ���̸� ��������ȯ�� �����ش�. ������ ���*/
	/*explicit*/SoSimple(const SoSimple &copy) //SoSimple ��ü�� ���ڷ� �޴� ������ �߰�, const�� �־� ������ �����Ű�� ���� ������ ������ ���ʶ߸��� �ʰ� �Ǽ��� ����
		:num1(copy.num1), num2(copy.num2) //�̴ϼȶ������� �̿��ؼ� ��� �� ����� ���縦 ����
	{
		cout << "Called SoSimple(&copy)" << endl; //ȣ�� Ȯ�ο� ����
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main()
{
	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1; //SoSimple sim2(sim1); �� �����ϴ�.
	cout << "���� �� �ʱ�ȭ ����" << endl;
	sim2.ShowSimpleData();

	return 0;
}