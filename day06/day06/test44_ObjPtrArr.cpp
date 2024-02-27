// file : test44_ObjPtrArr.cpp
// date : 2400227
// desc : ��ü �����͹迭

// ��ü ������ �迭 : ��ü�� �ּ� �� ������ ������ ������ ������ �̷���� �迭

# include<iostream>
# include<cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << ",";
		cout << "����: " << age << endl;
	}
	~Person() // �Ҵ����  �޸� ���� ��ȯ �Ҹ���
	{
		delete[]name; 
		cout << "called destructor!" << endl;
	}

};

int main(void)
{
	Person* parr[3]; // ��ü ������ �迭

	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�: ";
		cin >> namestr;
		cout << "����: ";
		cin >> age;
		parr[i] = new Person(namestr, age); // �Էµ� ���� �޾� heap������ ��ü�� �����ϰ� ���� ��ü�� �ּ� ���� �迭�� ���� 
	}

	parr[0]->ShowPersonInfo(); // �ַο� ������(->) : ��ü�����͸� ���ؼ� ����� ������ �� ���
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	delete parr[0];
	delete parr[1];
	delete parr[2];

	return 0;
}