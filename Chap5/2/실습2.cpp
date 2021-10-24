#include <iostream>
using namespace std;

void half(double& refn) {
	refn /= 2;
}

int main()
{
	double n = 20;
	half(n);
	cout << n << endl;
	return 0;
}