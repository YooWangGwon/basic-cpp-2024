// file : test55_PassObjCopycon.cpp
// date : 240228
// desc : 할당 이후, 복사 생성자를 통한 초기화

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
	void ShowData()	// 멤버 함수 : 객체 생성 후에 사용 가능
	{
		cout << "num: " << num << endl;
	}
};

// 어디에도 소속되어 있지 않는 전역함수 : 어디서든 접근 가능
void SimpleFuncObj(SoSimple ob)	// 객체 ob를 생성하는 복사생성자를 실행하여 객체 obj의 변수를 복사받는다.
{
	ob.ShowData();
}

int main(void)
{
	SoSimple obj(7);
	cout << "함수호출 전" << endl;
	SimpleFuncObj(obj);	// obj
	cout << "함수호출 후" << endl;
	return 0;
}