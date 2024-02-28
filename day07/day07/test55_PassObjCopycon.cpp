// file : test55_PassObjCopycon.cpp
// date : 240228
// desc : �Ҵ� ����, ���� �����ڸ� ���� �ʱ�ȭ

# include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const so Simple& copy)" << endl;
	}
	void ShowData()	// ��� �Լ� : ��ü ���� �Ŀ� ��� ����
	{
		cout << "num: " << num << endl;
	}
};

// ��𿡵� �ҼӵǾ� ���� �ʴ� �����Լ� : ��𼭵� ���� ����
void SimpleFuncObj(SoSimple ob)	// ��ü ob�� �����ϴ� ��������ڸ� �����Ͽ� ��ü obj�� ������ ����޴´�.
{
	ob.ShowData();
}

int main(void)
{
	SoSimple obj(7);
	cout << "�Լ�ȣ�� ��" << endl;
	SimpleFuncObj(obj);	// obj
	cout << "�Լ�ȣ�� ��" << endl;
	return 0;
}