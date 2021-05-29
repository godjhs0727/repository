#include <iostream>
using namespace std;

const int number = 8;
int sorted[8];

void merge(int* a, int m, int middle, int n)
{
	int i = m; //처음
	int j = middle + 1;
	int k = m;
	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//남은 데이터 삽입
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열을 다시 삽입
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	//이외의 경우는 크기가 1개인 경우이다.
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(a, m, middle); //계속 1개로 나눈다.
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n); //그리고 마지막으로 merge병합
	}
}

int main()
{
	int arr[number] = { 5,2,1,3,8,6,7,4 };
	mergeSort(arr, 0, number - 1);
	for (int i = 0; i < number; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}