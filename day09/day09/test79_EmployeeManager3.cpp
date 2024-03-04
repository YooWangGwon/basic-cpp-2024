// file : test79_EmployeeManager3.cpp
// date : 240304
// desc : �������̵�(OverRiding)(p.330~333)

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
};

class PermanentWorker : public Employee	// Employee Ŭ������ ���
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)	// �θ� Ŭ������ �����ڸ� ȣ���Ͽ� name�� �ʱ�ȭ
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

class TemporaryWorker : public Employee	// Employee Ŭ������ ����ϴ� SalesWorker Ŭ���� ����
{
private:
	int workTime;	// �� �޿� ���� �ð��� �հ�
	int payPerHour; // �ð��� �޿�
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time) // ���� �ð��� �߰�
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

class SalesWorker : public PermanentWorker	// PermanentWorker Ŭ������ ����ϴ� SalesWorker Ŭ���� ����
{
private:
	int salesResult;	// �� �ǸŽ���
	double bonusRatio;	// �󿩱� ����
public:
	SalesWorker(const char*name, int money, double ratio)
		: PermanentWorker(name,money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		cout << "Sales Worker" << endl;		// �������̵� �� ����Լ��� �ڽ��� ����Լ��� �켱�Ͽ� ����
		return PermanentWorker::GetPay()	// ���� �����ǵ� �θ��� ����Լ��� ȣ���Ϸ��� '���� ������'�� ���� PermanentWorker Ŭ����(�θ� Ŭ����)�� GetPay�Լ��� ���� ȣ���ؾ� ��
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();										// ShowSalaryInfo �Լ��� ������ ���������� �ʰ� PermanentWorker�� ���� �״�� ����Ѵٸ� PermanentWorker�� GetPay�Լ��� ȣ���ϰ� ��
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker�� GetPay�Լ� ȣ���ϱ� ���� ShowSalaryInfo �Լ��� ������
	}
};
class EmployeeHandler	// ��Ʈ��(control) Ŭ���� or �ڵ鷯(handler) Ŭ���� : ����� ó���� ������ ����ϴ� Ŭ����
{
private:
	Employee* empList[50];	// Employee(�����)Ÿ���� ��ü ������ �迭
	int empNum;
public:
	EmployeeHandler() : empList(), empNum(0)	// nullptr �ʱ�ȭ
	{ }
	void AddEmployee(Employee* emp)	// ���ο� ���� ���� ��� : ������ ��ü�� �ּҸ� �Է¹��� -> �Է¹��� ��ü�� �ּҸ� empList�迭�� �������
	{
		empList[empNum++] = emp;	// ó���� 0��° �濡 �ְ��� 1����
	}
	void ShowAllSalaryInfo() const	// ��� ������ �̹� �� �޿����� ���
	{
		/*
		for (int i = 0; i < empNum; i++)
			empList[i]-> ShowSalaryInfo();	// empList�� ����ִ� ��(empList�� ��Ұ�)���� �ּҰ�(������)�̱� ������ �ַο쿬����(->)�� Ȱ���ؼ� ����Լ��� ����
		*/
	}
	void ShowTotalSalary() const	// �̹� �� �޿��� �Ѿ� ���
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();	// empList�� ����ִ� ��(empList�� ��Ұ�)���� �ּҰ�(������)�̱� ������ �ַο쿬����(->)�� Ȱ���ؼ� ����Լ��� ����
		*/
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

	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);


	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	
	SalesWorker s("Hong", 1000, 0.1);
	s.AddSalesResult(1000);
	s.ShowSalaryInfo();


	return 0;


}