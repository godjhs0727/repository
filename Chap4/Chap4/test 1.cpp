/*정수 공간 5개를 배열로 동적할당 받고, 정수를 5개 입력받아
평균을 구하고 출력한 뒤 배열을 소멸시키도록 main()함수를 작성하라.*/
#include <iostream>
using namespace std;

int main() {
	int* p = new int[5];
	int sum = 0;
	cout << "정수 5개 입력>> ";
	for (int i = 0; i < 5; i++)
		cin >> p[i];
	for (int i = 0; i < 5; i++)
		sum += p[i];
	cout << "평균 : " << sum / 5.0;
}