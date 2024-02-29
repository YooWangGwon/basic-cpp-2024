// file : test73_DerivDestOrder.cpp
// date : 240229
// desc : 유도 클래스 객체의 소멸과정(p.291~292)

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
	return 0;	// 유도 클래스의 객체가 소멸될 때에는 , 유도 클래스의 소멸자가 실행되고 난 다음에 기초 클래스의 소멸자가 실행된다
				// 스택에 생성된 객체의 소멸순서는 생성순서와 반대이다
}