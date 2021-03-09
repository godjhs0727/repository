#include <stdio.h>
#include <Windows.h>

int main()
{	
	//핵심1. 주소를 저장할 수 있음
	//핵심2. (주소에 + 연산자를 사용하면, 타입의 바이트 수만큼 건너뛴 다음 주소 자리임)
	char a = 10; //주소에다가 연산을 하면 그 타입의 바이트 양 만큼 오른다.
	printf("a의 값은 %d 이다.\n", a);
	printf("a + 1 의 값은 %d 이다.\n", a + 1);

	printf("a의 주소는 %x 이다.\n", &a);
	printf("a의 주소 + 1은 %x 이다.\n", &a + 1);

	//포인터란? 주소를 저장할 수 있는 데이터 타입이다. 데이터타입 뒤에 별이 있으면 그게 포인터이다.
	char* ptr;

	ptr = &a;
	printf("ptr의 값은 %x\n", ptr);
	
	//핵심3. 원본값 수정
	float pi = 3.141592f;
	float* pPi = &pi;

	printf("pi : %f\n", pi);
	printf("pPi : %x\n", pPi);
	printf("pPi : %f\n", *pPi);

	*pPi = 99.9f;
	printf("pi : %f\n", pi);

	//핵심4. 동적 할당(Dynamic Allocate) Stack, Heap 연구해보기 빌드타임 런타임...
	//과제 숫자야구 배열 이용해서.



	system("pause");
	return 0;
}