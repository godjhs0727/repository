#include <iostream>
using namespace std;

void Counter()
{
	static int cnt; //static 변수는 전역변수와 마찬가지로 초기화하지 않으면 0으로 초기화된다. 그리고 이 문장은 딱 한번 실행이 된다.
	//즉, cnt는 Counter함수가 호출될 때마다 새롭게 할당되는 지역변수가 아니다.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
		Counter();

	return 0;
}