#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker // 데이터적 성격이 강한 클래스
{
private:
	char name[100];
	int salary; //매달 지불해야하는 급여액
public:
	PermanentWorker(const char* name, int money)
		:salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};
class EmployeeHandler //기능적 성격이 강한 클래스
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0) {};
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};
int main()
{
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;
	//직원등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//이번달 지불해야할 급여의 정보
	handler.ShowAllSalaryInfo();

	//이번달 지불해야할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}