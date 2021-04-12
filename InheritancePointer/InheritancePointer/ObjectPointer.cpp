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
	Person *ptr1 = new Student(); //Student는 Person으로부터 상속받았으므로, Person형 포인터 변수는 Student 객체를 가리킬 수 있다.
	Person *ptr2 = new PartTimeStudent();
	Student *ptr3 = new PartTimeStudent();
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}