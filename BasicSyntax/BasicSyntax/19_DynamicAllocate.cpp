#include <stdio.h>
#include <Windows.h>
//동적할당
int main()
{
	//int* ptr; //int포인터든 double포인터든 몇 비트 체계이느냐에 따라서 4바이트 혹은 8바이트
	////포인터니깐 4바이트 new double로 붙으면 heap 영역에 8바이트로 저장 된다.


	//ptr = new int; //heap 영역에 4바이트를 요청한다. new를 받으면 프로그램이 죽지 않는다?
	//*ptr = 50;
	//printf("동적 할당 받은 주소 : %x\n", ptr);
	//printf("동적 할당 받은 주소에 들어 있는 값 : %d\n", *ptr);
	//delete ptr; //안에 값은 그대로지만 연결되어 있던 링크는 끊어진다.
	//
	//
	
	printf("학생의 수 : ");
	int input;
	scanf("%d", &input);
	
	int* student = new int[input]; //new를 해주면 반드시 delete를 해주어야 한다.
	int score;

	//입력
	printf("점수 입력 시작\n");
	for (int i = 0; i < input; i++)
	{
		printf("%d 번째 입력 : ", i);
		scanf("%d", &student[i]);
		
	}

	//출력
	printf("출력 시작\n");
	
	for (int i = 0; i < input; i++)
	{
		printf("%d 번째 출력 %d\n",i, *(student + i));// ==student[i]
	}
	
	delete[] student;//반드시 배열기호[]가 들어와야 한다.

	int *pp = new int;
	*pp = 30;
	delete pp;
	printf("%d\n", *pp);

	/*int arr[3] = { 100, 200, 300 };
	printf("%x\n", arr);
	printf("%x\n", &arr[0]);
	printf("%x\n", &arr[1]);
	printf("%x\n", &arr[2]);

	printf("%d\n", *(arr + 1));
	printf("%d\n", arr[1]);*/

	system("pause");
	return 0;
}


// -> 함수 : Function, prededure(프로시저)
// -> Call By Value
// -> Call By Address
// -> Call By Reference 조사 과제