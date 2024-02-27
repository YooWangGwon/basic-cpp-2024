// file : test41_Destructor.cpp
// date : 240227
// desc : 소멸자(p.187~190)

# include <iostream>
# include <cstring>
using namespace std;

class Person
{
private:
	char* name; // 포인트 타입으로 속성을 가지고 있음
	int age;
public:
	Person(const char* myname, int myage) // 입력 2개를 갖는 생성자
	{
		int len = strlen(myname) + 1;	  // strlen():문자열의 길이 측정, +1을 하는 이유:문자들의 배열인 문자열이기 때문에 null 값을 넣어줘야 하기 위함(C 한정)
		name = new char[len];			  // 문자열의 길이만큼 힙영역에서 메모리를 할당받고 그 주소를 name에 연결, 힙 영역에 새로운 메모리 영역을 할당(별도의 객체 생성)
		cout << sizeof(len) << endl;
		cout << "char 크기: " << sizeof(char) << endl;
		strcpy(name, myname);			  // myname에 있는 문자열을 복사해서 힙 영역(동적영역)에 만든 name에 저장
		age = myage;
	}
	// name과 myname이 가리키는 문자열은 서로 다른 문자열. name에 있는 문자열은 new연산자를 통해 heap영역에 별도로 할당받은 메모리 공간에 저장하기 때문
	
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person() // 소멸자 : 객체가 생성되면 자동으로 호출됨 -> return되기 전에 자동으로 실행됨(객체가 2개 생성되어 소멸자도 2번 호출됨)
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29); // 정적영역
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}