//문1) 예제 DefaultValue3.cpp에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정'
//형태가 아닌, '함수 오버로딩'의 형태로 재 구현해보자. 물론 main 함수는
//변경하지 않아야 하며, 실행결과도 동일해야 한다.

#include <iostream>
using namespace std;

int BoxVolume()
{
	return 0;
}
int BoxVolume(int length)
{
	return length;
}
int BoxVolume(int length, int width)
{
	return length * width;
}
int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}

int main()
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	cout << "[D, D, D] : " << BoxVolume() << endl;

	return 0;
}

//문2) 다음과 같은 형태로의 함수 오버로딩은 문제가 있다.
//어떠한 문제가 있는지 설명해보자.
/*
int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}
*/
//이유 Default 값이 10도 아니고 11도 아니게 된다.