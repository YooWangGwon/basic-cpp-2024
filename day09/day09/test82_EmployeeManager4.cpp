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
	virtual int GetPay() const
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const
	{ }
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
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
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
		
		for (int i = 0; i < empNum; i++)
			empList[i]-> ShowSalaryInfo();	// ShowSalaryInfo�� �����Լ��� ���� ��ü ������ �迭 ���� ��ü �����Ͱ� ����Ű�� ��ü�� Ÿ�Կ� ���� ������ ����Լ��� ������ 
		
	}
	void ShowTotalSalary() const	// �̹� �� �޿��� �Ѿ� ���
	{
		int sum = 0;
		
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();	// GetPay�� �����Լ��� ���� ��ü ������ �迭 ���� ��ü �����Ͱ� ����Ű�� ��ü�� Ÿ�Կ� ���� ������ ����Լ��� ������ 
											// �θ��� ��ü�� ���ؼ� �ڽ��� ��ü�� ����(������ �Ȱ��� �ڽ�Ÿ���� ��ü �����͸� ������ �ʿ� ���� �θ� Ÿ���� �����͸� Ȱ���Ͽ� �ڽ� Ÿ���� ��ü�� ���� ����)
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
	handler.AddEmployee(new PermanentWorker("KIM", 1000));	// ������ ��ü ���� �� ������ ���� ���
	handler.AddEmployee(new PermanentWorker("LEE", 1500));	// new �����ڸ� ���� heap������ ��ü ����

	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);	// �ӽ��� ��ü ���� �� ������ ���� ���
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);	// ������ ��ü ���� �� ������ ���� ���
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);


	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}