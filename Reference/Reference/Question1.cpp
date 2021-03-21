#include <iostream>
using namespace std;

/*
문제1) 참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하여라.
인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
인자로 전달된 int형 변수의 부호를 바꾸는 함수

그리고 위의 각 함수를 호출하여 그 결과를 확인하는 main 함수까지 작성하여라

문제2) 앞서 소개한 예제 RefSwap.cpp 의 SwapByRef2 함수를 다음의 형태로 호출하면 컴파일 에러가 발생한다
SwapByRef2(23,45);
컴파일 에러가 발생하는 이유가 무엇인지 설명해보자

--설명 : RefSwap.cpp의 SwapByRef2의 매개변수는 참조자 int & 이기 때문에 int형 정의된 매개변수가 필요하다.
23과 45를 swap하는 함수를 만드는 예는 아래와 같다.
*/
/*
문제3)
문제의 제시에 앞서 먼저 다음 코드를 보자.
int main()
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	. . .
}
위의 코드를 보면 ptr1과 ptr2가 각각 num1과 num2를 가리키고 있다. 이 때 ptr1과 ptr2를 대
상으로 다음과 같이 함수를 호출하고 나면,
SwapPointer(ptr1,ptr2);
ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 SwapPointer 함수를 정의해보자.
*/

//문제1)
void PlusOne(int &a)
{
	a = a + 1;
}
void Reverse(int &a)
{
	a = -a;

}
//문제2)
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << a << ' ' << b << endl;
}
//문제3)
void SwapPointer(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int n = 10;
	int num1 = 0;
	int num2 = 20;
	int *ptr1 = &num1;
	int *ptr2 = &num2;
	SwapPointer(ptr1, ptr2);

	PlusOne(n);
	Reverse(n);
	Swap(23, 45);
	cout << n << endl;
	cout << *ptr1 << ' ' << *ptr2 << endl;

	return 0;
}