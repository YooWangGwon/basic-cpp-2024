// file : test39_ReferenceMember.cpp
// date : 240227
// desc : ��������� ������ ����

# include <iostream>
using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl; // ��ü ���� ���� Ȯ�� ����
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;		//�����ڰ� ��������� ����� -> �̴ϼȶ����� ��� 
	const int& num; //const �����ڰ� ��������� ����� -> �̴ϼȶ����� ��� 

public:
	BBB(AAA& r, const int& n)  
		: ref(r), num(n)		// �̴ϼȶ����� ���	
	{
	}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}