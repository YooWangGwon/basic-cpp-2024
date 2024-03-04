// file : test79_EmployeeManager3.cpp
// date : 240304
// desc : 오버라이딩(OverRiding)(p.330~333)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const
	{ }
};

class PermanentWorker : public Employee	// Employee 클래스를 상속
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)	// 부모 클래스의 생성자를 호출하여 name을 초기화
	{	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee	// Employee 클래스를 상속하는 SalesWorker 클래스 선언
{
private:
	int workTime;	// 이 달에 일한 시간의 합계
	int payPerHour; // 시간당 급여
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time) // 일한 시간의 추가
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker	// PermanentWorker 클래스를 상속하는 SalesWorker 클래스 선언
{
private:
	int salesResult;	// 월 판매실적
	double bonusRatio;	// 상여금 비율
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay()	// 따라서 재정의된 부모의 멤버함수를 호출하려면 '범위 스코프'를 통해 PermanentWorker 클래스(부모 클래스)의 GetPay함수를 따로 호출해야 함
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();										// ShowSalaryInfo 함수를 별도로 재정의하지 않고 PermanentWorker의 것을 그대로 사용한다면 PermanentWorker의 GetPay함수를 호출하게 됨
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker의 GetPay함수 호출하기 위해 ShowSalaryInfo 함수를 재정의
	}
};
class EmployeeHandler	// 컨트롤(control) 클래스 or 핸들러(handler) 클래스 : 기능의 처리를 실제로 담당하는 클래스
{
private:
	Employee* empList[50];	// Employee(고용인)타입의 객체 포인터 배열
	int empNum;
public:
	EmployeeHandler() : empList(), empNum(0)	// nullptr 초기화
	{ }
	void AddEmployee(Employee* emp)	// 새로운 직원 정보 등록 : 정규직 객체의 주소를 입력받음 -> 입력받은 객체의 주소를 empList배열에 집어넣음
	{
		empList[empNum++] = emp;	// 처음에 0번째 방에 넣고나서 1증가
	}
	void ShowAllSalaryInfo() const	// 모든 직원의 이번 달 급여정보 출력
	{
		
		for (int i = 0; i < empNum; i++)
			empList[i]-> ShowSalaryInfo();	// ShowSalaryInfo를 가상함수로 만들어서 객체 포인터 배열 내의 객체 포인터가 가리키는 객체의 타입에 따라 실행할 멤버함수가 결정됨 
		
	}
	void ShowTotalSalary() const	// 이번 달 급여의 총액 출력
	{
		int sum = 0;
		
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();	// GetPay를 가상함수로 만들어서 객체 포인터 배열 내의 객체 포인터가 가리키는 객체의 타입에 따라 실행할 멤버함수가 결정됨 
											// 부모의 객체를 통해서 자식의 객체에 접근(일일히 똑같은 자식타입의 객체 포인터를 생성할 필요 없이 부모 타입의 포인터를 활용하여 자식 타입의 객체에 접근 가능)
		cout << "salary sum: " << sum << endl;

	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	// 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	// 직원등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));	// 정규직 객체 생성 및 포인터 변수 등록
	handler.AddEmployee(new PermanentWorker("LEE", 1500));	// new 연산자를 통해 heap영역에 객체 생성

	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);	// 임시직 객체 생성 및 포인터 변수 등록
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);	// 영업직 객체 생성 및 포인터 변수 등록
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);


	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}