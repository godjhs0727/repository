#include <iostream>
using namespace std;
template <typename T>
inline T square(T x)
{
	return x * x;
}

//매크로와 비교
#define Square(x) ((x)*(x)) //매크로는 자료형에 얽매이지 않는다.

inline int SQUARE(int x) //inline 은 자료형에 얽매인다 template 를 사용해서 데이터 손실을 막는다.
{
	return x * x;
}
int main()
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(12) << endl << endl;
	cout << Square(6) << endl;
	cout << Square(3.14) << endl << endl;
	cout << square(5) << endl;
	cout << square(3.14) << endl;


	return 0;
}