// file : test78_ObjectPointer
// date : 240304
// desc : 객체 포인터 변수

# include<iostream>
using namespace std;

class Person	// 1개의 멤버 함수 보유
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person	// 2개의 멤버 함수 보유
{
public:
	void Study() { cout << "Study" << endl; }
	void Sleep() { cout << "Sleep" << endl; } // 오버라이딩(OverRiding) : 상위 클래스의 함수를 하위 클래스에서 재정의
};

class PartTimeStudent : public Student	// 3개의 멤버 함수 보유
{
public: 
	void Work() { cout << "Work" << endl; }
};

int main(void)
{
	Student* ptr0 = new Student();			// 기본적으로 동일한 타입으로 사용하는 것이 원칙이다
	Person* ptr1 = new Student();			// Person형 포인터 변수(부모 클래스)가 Student 객체(자식 클래스)를 가리킴
	Person* ptr2 = new PartTimeStudent();	// Person형 포인터 변수가 PartTimeStudent 객체를 가리킴
	Student* ptr3 = new PartTimeStudent();	// Student형 포인터 변수가 PartTimeStudent 객체를 가리킴
	ptr1->Sleep();	// 객체 타입인  Student의 Sleep()함수가 아닌 객체 포인터 타입인 Person의 Sleep() 함수 사용 -> 접근은 객체 포인터의 타입을 따름
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}

/*
- 부모 타입의 객체 포인터로 자식 객체를 가리킬 수 있음
- 자식 타입의 객체 포인터로 부모 타입 객체를 가리킬 수 없음
- 접근은 객체 포인터의 타입을 따름
*/