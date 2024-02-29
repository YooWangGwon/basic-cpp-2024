// file : test77_InheritanceTraining.cpp
// date : 240229
// desc : ��� �ǽ�

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
		cout << "���� �̸��� " << Myname() << "�̰� ���̴� " << Myage() << "���̸� ��ȭ��ȣ�� " << pNumber << "�̰� �������� "<< address << "�Դϴ�." << endl;
	}
	void Move(const char* newaddress)
	{
		strcpy(address, newaddress);
	}
};


int main(void)
{
	MyInfo p1("���ձ�", 25, "010-1234-5678","�λ�");
	p1.printMyInfo();
	p1.Move("����");
	p1.printMyInfo();
	return 0;
}