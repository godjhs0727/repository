/*
문제
const 포인터에 대한 복습을 겸할 수 있는 문제. 다음의 상수선언을 해보자
const int num = 12;

포인터 변수를 선언해서 위 변수를 가리키게 해보자. 그리고 이 포인터 변수를 참조하는 참조자를
하나 선언하자. 마지막으로 이렇게 선언된 포인터 변수와 참조자를 이용해서 num에 저장된 값을
출력하는 예제를 완성해보자.
*/
#include <iostream>
using namespace std;

int main()
{
	const int num = 12;
	const int *ptr = &num; //위에가 const int이기에 포인터도 동일한 const로 상수화한다.
	const int *(&ref) = ptr; //위와 같은 이유로 const하고 포인터이기에 참조자괄호 후 포인터

	cout << *ptr << endl;
	cout << *ref << endl;


	return 0;
}