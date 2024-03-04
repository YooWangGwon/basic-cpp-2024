// file : test86_ReferenceAttribute.cpp
// date : 240304
// desc : 참조자의 참조가능성(p.360~362)

# include<iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
}; 

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;			// // Third 클래스 타입 객체 obj 생성
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();
	
	cout << endl;
	Second& sref = obj;	// Third 클래스 타입 객체 obj를 Second 클래스 타입 참조자로 참조
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();	// SimpleFunc는 가상함수로 Third 클래스의 SimpleFunc함수가 호출됨

	cout << endl;
	First& fref = obj; 	// Third 클래스 타입 객체 obj를 First 클래스 타입 참조자로 참조
	fref.FirstFunc();
	fref.SimpleFunc();	// // SimpleFunc는 가상함수로 Third 클래스의 SimpleFunc함수가 호출됨
	return 0;
}