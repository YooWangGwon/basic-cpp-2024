# include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)					// ���� �ϳ��� �Է����� �޴� ������
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)		// ��ü �ϳ��� �Է����� ���� ������
	{
		cout << "AAA(const AAA&ref)" << endl;
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA&ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;	//	AAA Ÿ���� ��ü
public:
	BBB(const AAA&ref):mem(ref) { }	// ��� �̴ϼȶ�����(�ݷ� �ʱ�ȭ)�� ���ؼ� �ʱ�ȭ
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) 
	{ 
		mem = ref;	// ���� �����ڸ� ���ؼ� �ʱ�ȭ
	}
};

int main(void)
{
	AAA obj1(12);
	cout << "***************" << endl;
	BBB obj2(obj1);	// �ѹ��� ȣ��
	cout << "***************" << endl;
	CCC obj3(obj1);	// 2 �ܰ踦 ���ļ� ȣ��
	return 0;
}