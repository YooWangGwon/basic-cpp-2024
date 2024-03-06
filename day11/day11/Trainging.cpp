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
		cout << name << "의 세 과목 총 점수는 " << kr + math + english << "점 입니다." << endl;;
	}
	void ShowAverage()
	{
		cout << name << "의 세 과목 평균 점수는 " << (kr + math + english) / 3 << "점 입니다." << endl;;
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

	cout << "총점" << sum << "점" << endl;
	cout << "평균" << average << "점" << endl;
}

int main(void)
{
	/*
	Grade st1("철수", 90, 100, 100);
	Grade st2("짱구", 70, 80, 80);
	Grade st3("훈이", 80, 80, 80);
	Grade st4("유리", 90, 70, 80);
	Grade st5("맹구", 100, 90, 90);

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
		cout << "이름 국어점수 수학점수 영어점수를 입력하세요" << endl << "(띄어쓰기로 구분하세요)" << endl;
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



	cout << "국어" << endl;
	ShowSubject(krgrade);

	cout << "수학" << endl;
	ShowSubject(mathgrade);

	cout << "영어" << endl;
	ShowSubject(englishgrade);

	return 0;
}