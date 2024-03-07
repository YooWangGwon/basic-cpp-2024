#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;


class Grade
{
private:
	char name[50];
	int kr;
	int math;
	int english;
public:
	void SetInfo(const char* Sname, int Skr=0, int Smath=0, int Senglish=0)
	{
		strcpy(name, Sname);
		kr = Skr;
		math = Smath;
		english = Senglish;
	}
	void ShowTotalGrade() const
	{
		cout << name << "�� �� ���� �� ������ " << kr + math + english << "�� �Դϴ�." << endl;;
	}
	void ShowAverage() const
	{
		cout << name << "�� �� ���� ��� ������ " << (kr + math + english) / 3 << "�� �Դϴ�." << endl;;
	}
	int ShowKr() const		// �ܺο��� ���� ���� ����
	{
		return kr;
	}
	int ShowMath() const	// �ܺο��� ���� ���� ����
	{
		return math;
	}
	int ShowEng() const		// �ܺο��� ���� ���� ����
	{
		return english;
	}
};

int main(void)
{
	Grade student[5] = {  };
	char Sname[50];
	int Skr = 0;
	int Smath = 0;
	int Senglish = 0;
	int memberNum = 0;
	int krsum=0, kravg=0,mathsum=0, mathavg=0, engsum=0,engavg = 0;

	cout << "�л� ���� �Է��ϼ���." << endl;
	cin >> memberNum;
	for (int i = 0; i < memberNum; i++)
	{
		cout << "�̸� �������� �������� ���������� �Է��ϼ���" << endl << "(����� �����ϼ���)" << endl;
		cin >> Sname >> Skr >> Smath >> Senglish;
		student[i].SetInfo(Sname, Skr, Smath, Senglish);
	}

	for (int i = 0; i < memberNum; i++)
	{
		student[i].ShowTotalGrade();	// �л� ����
		student[i].ShowAverage();		// �л� ���
		krsum += student[i].ShowKr();		// ���� ����
		kravg = krsum / memberNum;			// ���� ���
		mathsum += student[i].ShowMath();	// ���� ����
		mathavg = mathsum / memberNum;		// ���� ���
		engsum += student[i].ShowEng();		// ���� ����
		engavg = engsum / memberNum;		// ���� ���
	}
	cout << "����" << "����" << krsum << "��" << endl << "���" << kravg << "��" << endl;
	cout << "����" << "����" << mathsum << "��" << endl << "���" << mathavg << "��" << endl;
	cout << "����" << "����" << engsum << "��" << endl << "���" << engavg << "��" << endl;

	return 0;
}