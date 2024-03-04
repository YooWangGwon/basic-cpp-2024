// file : test70_EmployeeManager
// date : 240229
// desc : 상속(Inheritance)

	#define _CRT_SECURE_NO_WARNINGS
	#include <iostream>
	using namespace std;

	class PermanentWorker
	{
	private:
		char name[100];
		int salary;
	public:
		PermanentWorker(const char* name, int money)
			: salary(money)
		{
			strcpy(this->name, name);
		}
		int GetPay() const
		{
			return salary;
		}
		void ShowSalaryInfo()
		{
			cout << "name: " << name << endl;
			cout << "salary: " << salary << endl << endl;
		}
	};

	class EmployeeHandler	// 컨트롤(control) 클래스 or 핸들러(handler) 클래스 : 기능의 처리를 실제로 담당하는 클래스
	{
	private:
		PermanentWorker* empList[50];	// PermanentWorker(정규직)타입의 객체 포인터 배열
		int empNum;
	public:
		EmployeeHandler() : empNum(0)
		{ }
		void AddEmployee(PermanentWorker* emp)	// 새로운 직원 정보 등록 : 정규직 객체의 주소를 입력받음 -> 입력받은 객체의 주소를 empList배열에 집어넣음
		{
			empList[empNum++] = emp;	// 처음에 0번째 방에 넣고나서 1증가
		}
		void ShowAllSalaryInfo() const	// 모든 직원의 이번 달 급여정보 출력
		{
			for (int i = 0; i < empNum; i++)
				empList[i]->ShowSalaryInfo();	// empList에 들어있는 값(empList의 요소값)들이 주소값(포인터)이기 때문에 애로우연산자(->)를 활용해서 멤버함수에 접근
		}
		void ShowTotalSalary() const	// 이번 달 급여의 총액 출력
		{
			int sum = 0;
			for (int i = 0; i < empNum; i++)
				sum += empList[i]->GetPay();	// empList에 들어있는 값(empList의 요소값)들이 주소값(포인터)이기 때문에 애로우연산자(->)를 활용해서 멤버함수에 접근
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
		handler.AddEmployee(new PermanentWorker("KIM", 1000));	// new 연산자를 통해 heap영역에 객체 생성
		handler.AddEmployee(new PermanentWorker("LEE", 1500));
		handler.AddEmployee(new PermanentWorker("JUN", 2000));
	
		// 이번 달에 지불해야 할 급여의 정보
		handler.ShowAllSalaryInfo();

		// 이번 달에 지불해야 할 급여의 총합
		handler.ShowTotalSalary();
		return 0;
	}