// file : test41_Destructor.cpp
// date : 240227
// desc : �Ҹ���(p.187~190)

# include <iostream>
# include <cstring>
using namespace std;

class Person
{
private:
	char* name; // ����Ʈ Ÿ������ �Ӽ��� ������ ����
	int age;
public:
	Person(const char* myname, int myage) // �Է� 2���� ���� ������
	{
		int len = strlen(myname) + 1;	  // strlen():���ڿ��� ���� ����, +1�� �ϴ� ����:���ڵ��� �迭�� ���ڿ��̱� ������ null ���� �־���� �ϱ� ����(C ����)
		name = new char[len];			  // ���ڿ��� ���̸�ŭ ���������� �޸𸮸� �Ҵ�ް� �� �ּҸ� name�� ����, �� ������ ���ο� �޸� ������ �Ҵ�(������ ��ü ����)
		cout << sizeof(len) << endl;
		cout << "char ũ��: " << sizeof(char) << endl;
		strcpy(name, myname);			  // myname�� �ִ� ���ڿ��� �����ؼ� �� ����(��������)�� ���� name�� ����
		age = myage;
	}
	// name�� myname�� ����Ű�� ���ڿ��� ���� �ٸ� ���ڿ�. name�� �ִ� ���ڿ��� new�����ڸ� ���� heap������ ������ �Ҵ���� �޸� ������ �����ϱ� ����
	
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person() // �Ҹ��� : ��ü�� �����Ǹ� �ڵ����� ȣ��� -> return�Ǳ� ���� �ڵ����� �����(��ü�� 2�� �����Ǿ� �Ҹ��ڵ� 2�� ȣ���)
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29); // ��������
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}