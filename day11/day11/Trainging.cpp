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
	/*
	Grade(const char* Sname, int Skr, int Smath, int Senglish)
	{
		strcpy(name, Sname);
		kr = Skr;
		math = Smath;
		english = Senglish;
	}
	*/
	void SetInfo(const char* Sname, int Skr=0, int Smath=0, int Senglish=0)
	{
		strcpy(name, Sname);
		kr = Skr;
		math = Smath;
		english = Senglish;
	}
	void ShowTotalGrade()
	{
		cout << name << "�� �� ���� �� ������ " << kr + math + english << "�� �Դϴ�." << endl;;
	}
	void ShowAverage()
	{
		cout << name << "�� �� ���� ��� ������ " << (kr + math + english) / 3 << "�� �Դϴ�." << endl;;
	}
};
void ShowSubject(int arr[])
{
	int count = count(arr);
	int sum = 0;
	int average = 0;
	for (int i = 0; i < 2; i++)
	{
		sum += arr[i];
	}
	average = sum / 2;

	cout << "����" << sum << "��" << endl;
	cout << "���" << average << "��" << endl;
}

int main(void)
{
	/*
	Grade st1("ö��", 90, 100, 100);
	Grade st2("¯��", 70, 80, 80);
	Grade st3("����", 80, 80, 80);
	Grade st4("����", 90, 70, 80);
	Grade st5("�ͱ�", 100, 90, 90);

	st1.ShowAverage();
	st2.ShowTotalGrade();
	*/
	Grade student[2] = {  };
	char Sname[50];
	int Skr = 0;
	int Smath = 0;
	int Senglish = 0;

	int krgrade[2] = {  };
	int mathgrade[2] = {  };
	int englishgrade[2] = {  };

	for (int i = 0; i < 2; i++)
	{
		cout << "�̸� �������� �������� ���������� �Է��ϼ���" << endl << "(����� �����ϼ���)" << endl;
		cin >> Sname >> Skr >> Smath >> Senglish;
		student[i].SetInfo(Sname, Skr, Smath, Senglish);
		krgrade[i] = Skr;
		mathgrade[i] = Smath;
		englishgrade[i] = Senglish;
	}

	for (int i = 0; i < 2; i++)
	{
		student[i].ShowTotalGrade();
		student[i].ShowAverage();
	}



	cout << "����" << endl;
	ShowSubject(krgrade);

	cout << "����" << endl;
	ShowSubject(mathgrade);

	cout << "����" << endl;
	ShowSubject(englishgrade);

	return 0;
}