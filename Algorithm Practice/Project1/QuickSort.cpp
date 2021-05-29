#include <iostream>
using namespace std;

int n[] = { 6,10,3,5,4,9,2,7,8,1 };

void Show()
{
	for (int i = 0; i < 10; i++)
	{
		cout << n[i] << " ";
	}
}

void QuickSort(int*n, int start, int end)
{
	int key = start;
	int i = start + 1;
	int j = end, temp;
	if (start >= end)
		return;
	while (i <= j)
	{
		while (i <= end && n[i] <= n[key])
		{
			i++;
		}
		while (j > start && n[j] >= n[key])
		{
			j--;
		}
		if (i > j)
		{
			temp = n[j];
			n[j] = n[key];
			n[key] = temp;
		}
		else
		{
			temp = n[i];
			n[i] = n[j];
			n[j] = temp;
		}

		QuickSort(n, start, j - 1);
		QuickSort(n, j + 1, end);
	}
}

int main()
{
	QuickSort(n, 0, 9);
	Show();
	return 0;
}