// file : test75_ISAInheritance.cpp
// date : 240229
// desc : IS-A����(p.303~307)

# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Computer	// ��� ��ǻ���� �������� Ư¡�� ��Ÿ���� Computer Ŭ����
{
private:
	char owner[50];
public:
	Computer(const char* name)
	{
		cout << "Computer ������ ����" << endl;
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NotebookComp : public Computer	// Computer Ŭ������ ����� NotebookComp Ŭ����
{
private:
	int Battery;
public:
	NotebookComp(const char* name, int initChag) : Computer(name), Battery(initChag)	// owner�� Computer Ŭ������ private ����̱� ������ Computer �����ڸ� ����ؼ� �ʱ�ȭ
	{																					// ������� Battery�� NotebookComp�� ����̹Ƿ� NotebookComp �����ڷ� �ʱ�ȭ
		cout << "NotebookComp ������ ����" << endl;
	}																				
	void Charting() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();	// Computer Ŭ������ ����Լ� Caculate�� ��ӹ޾� ���
		UseBattery();	// Notebookcomp Ŭ������ ����Լ� UseBattery
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp // NotebookComp Ŭ������ ����� TabletNotebook Ŭ����. Computer Ŭ������ ����鵵 ���� ��ӹ���
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(const char* name, int initChag, const char* pen) : NotebookComp(name, initChag)	// ������� regstPenModel�� TabletNotebook Ŭ������ ����̹Ƿ� TabletNotebook �����ڷ� �ʱ�ȭ
	{																								// Battery�� NotebookComp �����ڷ� �ʱ�ȭ
		cout << "TabletNotebook ������ ����" << endl;												// owner�� NotebookComp �����ڸ� ���� Computer�����ڿ� �����Ͽ� �ʱ�ȭ
		strcpy(regstPenModel, pen);						
	}
	void Write(const char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("���ձ�", 5);
	TabletNotebook tn1("�̼���", 5, "ISE-241-242");
	TabletNotebook tn2("ȫ�浿", 10, "123-456-789");
	nc.MovingCal();
	nc.MovingCal();
	nc.MovingCal();
	nc.MovingCal();
	nc.MovingCal();
	nc.MovingCal();
	tn1.Write("ISE-241-242");
	tn2.Write("987-654-321");
	return 0;
}