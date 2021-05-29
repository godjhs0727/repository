#include <iostream>
using namespace std;

int main()
{
	int temp;
	int n[10] = { 5,1,2,3,6,4,9,7,8,10 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (n[j] > n[j + 1])
			{
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << n[i] << " ";
	}

	return 0;
}