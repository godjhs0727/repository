#include <iostream>
using namespace std;
int BoxVolume(int length, int width = 1, int height = 1);

int main()
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	//cout << "[D, D, D] : " << BoxVolume() << endl;
	//첫번째는 매개변수가 전부 바뀌어 적용
	//두번째는 length와 width가 바뀌어 나머지는 Default 값 1로 적용
	//세번째는 length만 7로 바뀌어 나머지 Default값 적용
	//마지막은 length가 Default값이 없어서 컴파일 에러!


	return 0;
}

int BoxVolume(int length, int width, int height)
{
	return length*width*height;
}
