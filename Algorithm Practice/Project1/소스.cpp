#include <iostream>
using namespace std;

int main()
{
	int n, m = 0;
	char l;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l;
		m += l - '0';
	}
	cout << m;
	return 0;
}