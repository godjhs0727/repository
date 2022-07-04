#include <iostream>
using namespace std;

struct ST {
	long a;		//8bytes
	int b;		//4bytes
	short c;	//2bytes
};

class Cat {
public:
	void printCat();
private:
	int age;	//4bytes
	float weight; //4bytes
};

int main() {
	cout << sizeof(ST) << endl;
	cout << sizeof(Cat) << endl;
	Cat cat1;
	Cat cat2;
	
	Cat* catPtr = &cat1;
	cout << sizeof(catPtr) << endl;

	return 0;
}