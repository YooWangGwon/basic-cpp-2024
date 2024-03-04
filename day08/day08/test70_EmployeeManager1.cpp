// file : test70_EmployeeManager
// date : 240229
// desc : ���(Inheritance)

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

	class EmployeeHandler	// ��Ʈ��(control) Ŭ���� or �ڵ鷯(handler) Ŭ���� : ����� ó���� ������ ����ϴ� Ŭ����
	{
	private:
		PermanentWorker* empList[50];	// PermanentWorker(������)Ÿ���� ��ü ������ �迭
		int empNum;
	public:
		EmployeeHandler() : empNum(0)
		{ }
		void AddEmployee(PermanentWorker* emp)	// ���ο� ���� ���� ��� : ������ ��ü�� �ּҸ� �Է¹��� -> �Է¹��� ��ü�� �ּҸ� empList�迭�� �������
		{
			empList[empNum++] = emp;	// ó���� 0��° �濡 �ְ��� 1����
		}
		void ShowAllSalaryInfo() const	// ��� ������ �̹� �� �޿����� ���
		{
			for (int i = 0; i < empNum; i++)
				empList[i]->ShowSalaryInfo();	// empList�� ����ִ� ��(empList�� ��Ұ�)���� �ּҰ�(������)�̱� ������ �ַο쿬����(->)�� Ȱ���ؼ� ����Լ��� ����
		}
		void ShowTotalSalary() const	// �̹� �� �޿��� �Ѿ� ���
		{
			int sum = 0;
			for (int i = 0; i < empNum; i++)
				sum += empList[i]->GetPay();	// empList�� ����ִ� ��(empList�� ��Ұ�)���� �ּҰ�(������)�̱� ������ �ַο쿬����(->)�� Ȱ���ؼ� ����Լ��� ����
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
		// ���� ������ �������� ����� ��Ʈ�� Ŭ������ ��ü����
		EmployeeHandler handler;

		// �������
		handler.AddEmployee(new PermanentWorker("KIM", 1000));	// new �����ڸ� ���� heap������ ��ü ����
		handler.AddEmployee(new PermanentWorker("LEE", 1500));
		handler.AddEmployee(new PermanentWorker("JUN", 2000));
	
		// �̹� �޿� �����ؾ� �� �޿��� ����
		handler.ShowAllSalaryInfo();

		// �̹� �޿� �����ؾ� �� �޿��� ����
		handler.ShowTotalSalary();
		return 0;
	}