#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
	string name;
	int score;
	Student(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	//정렬기준은 '점수가 작은 순서'
	bool operator <(Student &student)
	{
		return this->score < student.score;
	}
};

bool compare(Student a, Student b)
{
	return a.score < b.score;
}

int main()
{
	Student students[] = {
		Student("dd",90),
		Student("aa",80),
		Student("cc",98),
		Student("qq",86),
		Student("ee",100)
	};
	sort(students, students + 5, compare);
	for (int i = 0; i < 5; i++)
	{
		cout << students[i].name << endl;
	}
	return 0;
}