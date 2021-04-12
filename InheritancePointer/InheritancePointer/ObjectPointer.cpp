#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() const { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:
	void Study() const { cout << "Study" << endl; }
};

class PartTimeStudent : public Student
{
public:
	void Work() const { cout << "Work" << endl; }
};

int main()
{
	Person *ptr1 = new Student(); //Student�� Person���κ��� ��ӹ޾����Ƿ�, Person�� ������ ������ Student ��ü�� ����ų �� �ִ�.
	Person *ptr2 = new PartTimeStudent();
	Student *ptr3 = new PartTimeStudent();
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}