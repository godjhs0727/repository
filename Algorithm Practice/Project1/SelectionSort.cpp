#include <iostream>
using namespace std;

int main()
{
	//selection sort
	int n[10] = { 3,2,4,1,6,5,7,9,8,10 };
	int temp, index;
	for (int i = 0; i < 10; i++)
	{
		int max = 999;
		for (int j = i; j < 10; j++)
		{
			if (max > n[j])
			{
				max = n[j];
				index = j;
			}
		}
		temp = n[i];
		n[i] = n[index];
		n[index] = temp;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << n[i] << " ";
	}
	return 0;
}
