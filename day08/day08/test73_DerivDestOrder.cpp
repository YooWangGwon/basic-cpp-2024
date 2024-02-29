// file : test73_DerivDestOrder.cpp
// date : 240229
// desc : ���� Ŭ���� ��ü�� �Ҹ����(p.291~292)

# include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n) : " << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{
	SoDerived drv1(15);
	SoDerived drv2(27);
	return 0;	// ���� Ŭ������ ��ü�� �Ҹ�� ������ , ���� Ŭ������ �Ҹ��ڰ� ����ǰ� �� ������ ���� Ŭ������ �Ҹ��ڰ� ����ȴ�
				// ���ÿ� ������ ��ü�� �Ҹ������ ���������� �ݴ��̴�
}