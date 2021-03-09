#include "stdafx.h"
#include <vector>

int main()
{
	//vector : 가변길이 배열, 중간 삽입 삭제가 가능함
	vector<int> v; //int v[?] 템플릿 클래스

	//뒤에 삽입
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);


	//뒤를 삭제
	v.pop_back();//마지막에 있는걸 날리는 함수
	v.pop_back();
	v.push_back(15);
	
	//push_back() : 맨 뒤에 원소를 하나씩 추가
	//pop_back() : 맨 뒤 원소 한개를 삭제
	//begin() : 컨테이너의 시작 주소를 리턴
	//end() : 컨테이너의 끝 주소를 리턴
	//insert(where, value) : where 앞에 value를 중간 삽입 더미로도 넣을수 있다.
	//insert(where, range, value) : range 개수만큼 value를 중간 삽입
	//erase() : 중간 삭제
	//clear() : 전체 삭제
	//assign() : (1) vector <-> vector 간 복사, (2)배열화(pooling)
	//size() : 현재까지 추가된 원소의 개수를 리턴
	//capacity() : 실제 할당된 메모리의 개수 메모리를 넉넉히 잡는다?

	//iterator -> STL에서 각 원소들의 주소를 저장하기 위한 STL 전용 스마트 포인터
	/*vector<int>::iterator iter = v.begin();*/
	//vector<int>::iterator iter = v.end() - 1;
	//cout << "iter에 들어 있는 값은 : "<< *iter << endl; //iter는 값만 볼수 있다
	//cout << &v[0] << endl;
	//cout << "------------\n";
	//vector<int> test;
	//for (int i = 0; i < 100; i++)
	//{
	//	test.push_back(i);
	//	cout << "size : " << test.size() << ", capacity : " << test.capacity() << endl;
	//}

	//iterator


	
	//중간 삽입
	v.insert(v.begin() + 2, 99);//기존에 2번 인덱스에 삽입 2번 인덱스는 3번으로
	v.insert(v.end() - 2, 3, 100);


	////출력(배열 기반 출력)
	////for (int i = 0; i < v.size(); i++)
	////	cout << v[i] << endl;

	////출력(범위 기반 출력)
	//for (int i : v)
	//	cout << i << endl;

	//list는 양방향 포인터로 중간 삽입 삭제가 빠르나 검색은 느리다 vector는 반대

	//iterator를 사용한 출력
	vector<int>::iterator iter;
	for (iter = v.begin();iter != v.end()/*어디까지*/; iter++)
	{
		cout << *iter << endl;
	}


	//Range Based Loop
	//int arr[3] = { 100, 200, 300 };
	//for (int element : arr) //foreach(int element in arr) -> C#, JAVA버전
	//	cout << element << endl;

	system("pause");
	return 0;
}