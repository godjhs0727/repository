#include "stdafx.h"
#include <vector>

int main()
{
	//vector : �������� �迭, �߰� ���� ������ ������
	vector<int> v; //int v[?] ���ø� Ŭ����

	//�ڿ� ����
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);


	//�ڸ� ����
	v.pop_back();//�������� �ִ°� ������ �Լ�
	v.pop_back();
	v.push_back(15);
	
	//push_back() : �� �ڿ� ���Ҹ� �ϳ��� �߰�
	//pop_back() : �� �� ���� �Ѱ��� ����
	//begin() : �����̳��� ���� �ּҸ� ����
	//end() : �����̳��� �� �ּҸ� ����
	//insert(where, value) : where �տ� value�� �߰� ���� ���̷ε� ������ �ִ�.
	//insert(where, range, value) : range ������ŭ value�� �߰� ����
	//erase() : �߰� ����
	//clear() : ��ü ����
	//assign() : (1) vector <-> vector �� ����, (2)�迭ȭ(pooling)
	//size() : ������� �߰��� ������ ������ ����
	//capacity() : ���� �Ҵ�� �޸��� ���� �޸𸮸� �˳��� ��´�?

	//iterator -> STL���� �� ���ҵ��� �ּҸ� �����ϱ� ���� STL ���� ����Ʈ ������
	/*vector<int>::iterator iter = v.begin();*/
	//vector<int>::iterator iter = v.end() - 1;
	//cout << "iter�� ��� �ִ� ���� : "<< *iter << endl; //iter�� ���� ���� �ִ�
	//cout << &v[0] << endl;
	//cout << "------------\n";
	//vector<int> test;
	//for (int i = 0; i < 100; i++)
	//{
	//	test.push_back(i);
	//	cout << "size : " << test.size() << ", capacity : " << test.capacity() << endl;
	//}

	//iterator


	
	//�߰� ����
	v.insert(v.begin() + 2, 99);//������ 2�� �ε����� ���� 2�� �ε����� 3������
	v.insert(v.end() - 2, 3, 100);


	////���(�迭 ��� ���)
	////for (int i = 0; i < v.size(); i++)
	////	cout << v[i] << endl;

	////���(���� ��� ���)
	//for (int i : v)
	//	cout << i << endl;

	//list�� ����� �����ͷ� �߰� ���� ������ ������ �˻��� ������ vector�� �ݴ�

	//iterator�� ����� ���
	vector<int>::iterator iter;
	for (iter = v.begin();iter != v.end()/*������*/; iter++)
	{
		cout << *iter << endl;
	}


	//Range Based Loop
	//int arr[3] = { 100, 200, 300 };
	//for (int element : arr) //foreach(int element in arr) -> C#, JAVA����
	//	cout << element << endl;

	system("pause");
	return 0;
}