// file : test40_PrivateConductor.cpp
// date : 240227
// desc : Private ������

#include <iostream>
using namespace std;

class AAA
{
private:
	int num;

	AAA(int n) : num(n) {} // �ܺο����� ��ü ������ ����, �̱��� ������:��ü������ �� �ϳ��� �� �� ����ϴ� ������ ����(�޸� ����, ��ü�� ������ ������ �����ϴ°� �ʿ��� ���)

public:
	AAA() : num(0) {} // public���� default ������ ���� -> Ŭ���� �ܺο����� �Ʒ� �����ڸ� ������� ��ü�� ����

	AAA& CreatInitObj(int n) const // �Լ� ������, 17�࿡ ���ǵ� private �����ڸ� �̿��ؼ� AAA ��ü�� ���� �� ��ȯ 
	{
		AAA* ptr = new AAA(n); // new �����ڸ� ���� private�� �ִ� �����ڸ� �����Ͽ� ���������� ��ü��  ���� -> AAAŸ���� ������ ������ ����
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
};

int main(void)
{
	AAA base; // �̱��� Ư�� Ŭ������ �ν��Ͻ��� 1���� �����Ǵ� ���� �����ϴ� ������ ����
	base.ShowNum();	

	AAA& obj1 = base.CreatInitObj(3); // AAAŸ���� �������� obj1
	obj1.ShowNum();

	AAA& obj2 = base.CreatInitObj(12); // AAAŸ���� �������� obj2
	obj2.ShowNum();
	// obj1�� obj2�� ������ ��ü
	delete &obj1; // obj1 ��ȯ
	delete &obj2; // obj2 ��ȯ
	return 0;
}