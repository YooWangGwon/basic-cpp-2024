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
		cout << name << "의 세 과목 총 점수는 " << kr + math + english << "점 입니다." << endl;;
	}
	void ShowAverage() const
	{
		cout << name << "의 세 과목 평균 점수는 " << (kr + math + english) / 3 << "점 입니다." << endl;;
	}
	int ShowKr() const		// 외부에서 국어 점수 접근
	{
		return kr;
	}
	int ShowMath() const	// 외부에서 수학 점수 접근
	{
		return math;
	}
	int ShowEng() const		// 외부에서 영어 점수 접근
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

	cout << "학생 수를 입력하세요." << endl;
	cin >> memberNum;
	for (int i = 0; i < memberNum; i++)
	{
		cout << "이름 국어점수 수학점수 영어점수를 입력하세요" << endl << "(띄어쓰기로 구분하세요)" << endl;
		cin >> Sname >> Skr >> Smath >> Senglish;
		student[i].SetInfo(Sname, Skr, Smath, Senglish);
	}

	for (int i = 0; i < memberNum; i++)
	{
		student[i].ShowTotalGrade();	// 학생 총점
		student[i].ShowAverage();		// 학생 평균
		krsum += student[i].ShowKr();		// 국어 총점
		kravg = krsum / memberNum;			// 국어 평균
		mathsum += student[i].ShowMath();	// 수학 총점
		mathavg = mathsum / memberNum;		// 수학 평균
		engsum += student[i].ShowEng();		// 영어 총점
		engavg = engsum / memberNum;		// 영어 평균
	}
	cout << "국어" << "총점" << krsum << "점" << endl << "평균" << kravg << "점" << endl;
	cout << "수학" << "총점" << mathsum << "점" << endl << "평균" << mathavg << "점" << endl;
	cout << "영어" << "총점" << engsum << "점" << endl << "평균" << engavg << "점" << endl;

	return 0;
}