#include <iostream>
using namespace std;

int main()
{
	int n[10] = { 5,1,2,3,6,4,9,7,8,10 };
	int temp;
	for (int i = 0; i < 9; i++)
	{
		int j = i;
		while(j >= 0 && n[j] > n[j + 1])
		{
			temp = n[j];
			n[j] = n[j + 1];
			n[j + 1] = temp;
			j--;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << n[i] << " ";
	}

	return 0;
}