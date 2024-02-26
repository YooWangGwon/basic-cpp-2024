// file : test33_constructor
// date : 240226
// desc : 생성자

# include <iostream>
using namespace std;

class MyClass {
	int num;

public:
	MyClass() {
		cout << "생성자 호출: MyClass()" << endl;
		num = 10;
	}
	MyClass(int anum)
	{
		cout << "생성자 호출: MyClass(int )" << endl;
		num = anum;
	}
	void MyClassInfo()
	{
		cout << "num: " << num << endl;
	}
};

int main()
{
	//MyClass * m = new MyClass(); // heap영역에서 메모리를 할당받아 생성
	// MyClass m1(); ->m1이라는 함수를 호출하는 형태가 됨
	MyClass m2; // -> 객체생성 명령엉로 생성자는 자동 호출 됨
	m2.MyClassInfo();
	MyClass m3(20); // 인자가 달라져서 MyClass(int anum) 생성자가 호출됨
	m3.MyClassInfo();
	return 0;
}