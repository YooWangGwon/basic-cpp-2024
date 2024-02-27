// file : test51_CopyCon02.cpp
// date : 240227
// desc : 복사생성자2-디폴트 복사생성자

#include <iostream>
using namespace std;

class AA 
{
	int a;
	int b;
public:
	AA(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void AAInfo()
	{
		cout << a << " " << b << endl;
	}

};

int main()
{
	AA obj1(10, 20);
	obj1.AAInfo();
	AA obj2(obj1);	// 복사 생성자를 별도로 만들지 않아도 컴파일러가 자동으로 만들어서 호출함.
	obj2.AAInfo();	// 10, 20
	return 0;
}