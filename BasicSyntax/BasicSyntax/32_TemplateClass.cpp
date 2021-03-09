#include "stdafx.h" //cout 때문에 순서상의 문제 때문에 이게 더 먼저 쓰인다.
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
		mySelect->Get()->Print(); //여기까지가 객체	
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
->자료구조(Data Structure)
->자료들의 집합->컨테이너(배열)
*/