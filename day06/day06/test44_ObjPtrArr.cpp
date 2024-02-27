// file : test44_ObjPtrArr.cpp
// date : 2400227
// desc : 객체 포인터배열

// 객체 포인터 배열 : 객체의 주소 값 저장이 가능한 포인터 변수로 이루어진 배열

# include<iostream>
# include<cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ",";
		cout << "나이: " << age << endl;
	}
	~Person() // 할당받은  메모리 공간 반환 소멸자
	{
		delete[]name; 
		cout << "called destructor!" << endl;
	}

};

int main(void)
{
	Person* parr[3]; // 객체 포인터 배열

	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		parr[i] = new Person(namestr, age); // 입력된 값을 받아 heap영역에 객체를 생성하고 다음 객체의 주소 값을 배열에 저장 
	}

	parr[0]->ShowPersonInfo(); // 애로우 연산자(->) : 객체포인터를 통해서 멤버에 접근할 때 사용
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	delete parr[0];
	delete parr[1];
	delete parr[2];

	return 0;
}