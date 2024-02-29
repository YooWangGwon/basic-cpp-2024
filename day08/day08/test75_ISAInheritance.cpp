// file : test75_ISAInheritance.cpp
// date : 240229
// desc : IS-A관계(p.303~307)

# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Computer	// 모든 컴퓨터의 공통적인 특징을 나타내는 Computer 클래스
{
private:
	char owner[50];
public:
	Computer(const char* name)
	{
		cout << "Computer 생성자 실행" << endl;
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "요청 내용을 계산합니다." << endl;
	}
};

class NotebookComp : public Computer	// Computer 클래스를 상속한 NotebookComp 클래스
{
private:
	int Battery;
public:
	NotebookComp(const char* name, int initChag) : Computer(name), Battery(initChag)	// owner가 Computer 클래스의 private 멤버이기 때문에 Computer 생성자를 사용해서 초기화
	{																					// 멤버변수 Battery는 NotebookComp의 멤버이므로 NotebookComp 생성자로 초기화
		cout << "NotebookComp 생성자 실행" << endl;
	}																				
	void Charting() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
		Calculate();	// Computer 클래스의 멤버함수 Caculate를 상속받아 사용
		UseBattery();	// Notebookcomp 클래스의 멤버함수 UseBattery
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp // NotebookComp 클래스를 상속한 TabletNotebook 클래스. Computer 클래스의 멤버들도 따라서 상속받음
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(const char* name, int initChag, const char* pen) : NotebookComp(name, initChag)	// 멤버변수 regstPenModel은 TabletNotebook 클래스의 멤버이므로 TabletNotebook 생성자로 초기화
	{																								// Battery는 NotebookComp 생성자로 초기화
		cout << "TabletNotebook 생성자 실행" << endl;												// owner는 NotebookComp 생성자를 통해 Computer생성자에 접근하여 초기화
		strcpy(regstPenModel, pen);						
	}
	void Write(const char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("유왕권", 5);
	TabletNotebook tn1("이수종", 5, "ISE-241-242");
	TabletNotebook tn2("홍길동", 10, "123-456-789");
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