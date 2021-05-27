#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
public:
	Simple()
	{
		cout << "I'm simple constructor!" << endl;
	}
};
int main()
{
	cout << "case 1: ";
	Simple *sp1 = new Simple; //new할당 동시에 생성자

	cout << "case 2: ";
	Simple *sp2 = (Simple*)malloc(sizeof(Simple) * 1); //malloc함수호출을 통해서 힙 영역에 변수를 할당하지만 new와는 동작방식에 차이가 있다.

	cout << endl << "end of main" << endl;
	delete sp1;
	free(sp2);

	return 0;
}