#include <iostream>
using namespace std;

template <class T>
T biggest(T a[], int n) {
	T b = a[0];
	if (n <= 0) return 0;
	for (int i = 1; i < n; i++) {
		if (b < a[i])
			b = a[i];
	}
	return b;
}
int main(){
	int x[] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;
	double y[] = { 10.7,10.2,15.3,4.7 };
	cout << biggest(y, 4) << endl;

}