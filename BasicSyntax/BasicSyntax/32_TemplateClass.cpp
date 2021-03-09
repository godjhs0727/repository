#include "stdafx.h" //cout ������ �������� ���� ������ �̰� �� ���� ���δ�.
#include "32_TemplateClass.h"

int main()
{
	Brood* brood[3];

	brood[0] = new Terran;
	brood[1] = new Zerg;
	brood[2] = new Protoss;

	MySelect<Brood>* mySelect = new MySelect<Brood>;

	while (true)
	{
		int input;
		cout << "(1)Terran (2)Zerg (3)Protoss : ";
		cin >> input;

		mySelect->Set(brood[input - 1]);

		cout << " -> ";
		mySelect->Get()->Print(); //��������� ��ü	
	}
	for (int i = 0; i < ARRAYSIZE(brood); i++)
		delete brood[i];

	MySelect<Temp>* test = new MySelect<Temp>;
	Temp* whoami = new Temp;
	test->Set(whoami);

	string result = test->Get()->Print();
	cout << result.c_str() << endl;
	cout << test->Get()->Print().c_str() << endl;

	system("pause");
	return 0;
}
/*STL
->Standard Templat Library
->>vetor, list, stack, queue, tree, graph, hash, set..........
->�ڷᱸ��(Data Structure)
->�ڷ���� ����->�����̳�(�迭)
*/