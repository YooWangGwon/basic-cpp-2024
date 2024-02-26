// file : test33_constructor
// date : 240226
// desc : 생성자(p.169~171)

#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass()
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}
	/*
	SimpleClass(int n1 = 10, int n2 = 20) // 디폴트 매개변수를 주는 형태는 편리하지만 혼동을 줄 수 있기 때문에 잘 사용하지 않음
	{
		num1 = n1;
		num2 = n2;
	}
	*/
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc1;
	sc1.ShowData();

//	SimpleClass sc2(100);
//	sc2.ShowData();

//	SimpleClass sc3(100, 200);
//	sc3.ShowData();
	return 0;
}