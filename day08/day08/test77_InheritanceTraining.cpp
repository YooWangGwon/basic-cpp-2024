// file : test77_InheritanceTraining.cpp
// date : 240229
// desc : 상속 실습

# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace std;

class Myclass
{
private:
	char name[30];
	int age;
public:
	Myclass(const char * myname, int myage)
	{
		strcpy(name, myname);
		age = myage;
	}
	string Myname()
	{
		return name;
	}
	int Myage()
	{
		return age;
	}
};

class MyInfo : public Myclass
{
private:
	char pNumber[20];
public:
	MyInfo(const char* myname, int myage, const char* mypNum) : Myclass(myname, myage)
	{
		strcpy(pNumber, mypNum);
	}
	void printMyInfo()
	{
		cout << "나의 이름은 " << Myname() << "이고 나이는 " << Myage() << "살이며 전화번호는" << pNumber << "입니다." << endl;
	}
};

int main(void)
{
	MyInfo p1("유왕권", 25, "010-1234-5678");
	p1.printMyInfo();
	return 0;
}