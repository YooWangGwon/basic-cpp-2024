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
	char address[30];
	char newAddress[30];
public:
	MyInfo(const char* myname, int myage, const char* mypNum, const char* myaddress) : Myclass(myname, myage)
	{
		strcpy(pNumber, mypNum);
		strcpy(address, myaddress);
	}
	string MyAddress()
	{
		return address;
	}
	void printMyInfo()
	{
		cout << "나의 이름은 " << Myname() << "이고 나이는 " << Myage() << "살이며 전화번호는 " << pNumber << "이고 거주지는 "<< address << "입니다." << endl;
	}
	void Move(const char* newaddress)
	{
		strcpy(address, newaddress);
	}
};


int main(void)
{
	MyInfo p1("유왕권", 25, "010-1234-5678","부산");
	p1.printMyInfo();
	p1.Move("서울");
	p1.printMyInfo();
	return 0;
}