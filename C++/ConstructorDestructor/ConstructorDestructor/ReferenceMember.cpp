//�̴ϼȶ������� �̷��� Ư¡�� ��������� �����ڸ� ������ �� �ְ� �Ѵ�.
#include <iostream>
using namespace std;

class AAA
{
public:
	AAA(int n)
	{
		cout << "n = " << n << endl;
	}
	AAA()
	{
		cout << "empty object" << endl;
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA *ptr = new AAA(10);
	AAA &ref;
	const int &num;
public:
	BBB(AAA &r, const int &n)
		:ref(r), num(n){};
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
	~BBB()
	{
		delete ptr; //�����Ҵ� ����
		cout << "destructor" << endl;
	}
};

int main()
{
	//�����ڵ� const������ ���������� ����� ���ÿ� �ʱ�ȭ�� �̷����� �Ѵ�.
	//���� �̴ϼȶ������� �̿��ϸ� �����ڵ� ��������� ����� �� �ִ�.
	AAA obj1; //���⼭ AAA ������ �ߵ�
	BBB obj2(obj1, 20); //BBB private�� �ִ� �����Ҵ� �����ڰ� ȣ���, �̴ϼȶ������� �ʱ�ȭ ����
	obj2.ShowYourName(); //ù�� �ڵ忡 ���ؼ� AAA�� void�Լ� ȣ��, �� ���� �� �ڵ�, ���� �� �ڵ� ������� ������ �Ҹ��� ȣ��Ǿ new�Ҵ� ����

	return 0;
}