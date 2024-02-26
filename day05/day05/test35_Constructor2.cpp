// file : test35_Constructor2.cpp
// date : 240226
// desc : Constructor2(p.172~173)

#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc1(); // �Լ��� ���� ����
	SimpleClass mysc = sc1(); // sc1()�� ���ϰ��� ��ü sc�� ���� Ÿ���� mysc�� ����
	mysc.ShowData(); // 20 30 ���
	return 0; // �����Լ� ����
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30); // �Է� 2���� �޴� SimpleClass Ÿ���� sc ��ü ����
	return sc; // ��ü sc�� ����
}