// file : test100_AssignShallowCopyError.cpp
// date :240306
// desc : 디폴트 대입 연산자의 문제점

# include <iostream>
# include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person& operator=(const Person& ref)    // 깊은 복사를 위한 = 연산자 오버로딩
    {
        delete[]name; ;                 // 복사하기 전에 메모리의 누수를 막기 위해 기존에 가리키던 메모리 공간 반환
        int len = strlen(ref.name) + 1; 
        name = new char[len];           // heap영역에서 '복사 대상의 문자열 크기+1'만큼의 메모리 공간 할당 받음
        strcpy(name, ref.name);         // 복사 대상의 문자열을 복사하여 name 메모리 공간에 대입
        age = ref.age;
        return *this;                   // 결과로 복사된 Person객체 자시자신을 return
    }
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        delete[]name;   // 소멸하면서 name에 할당된 heap 영역의 메모리 공간을 반환
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2 = man1;    // man1의 값이 man2에 멤버대 멤버 대입됨. 디폴트 대입 연산자일 경우, man1과 man2가 동일한 주소값을 가지게됨 -> 동일한 메모리 공간을 가리키게 됨
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;       // man1이 소멸되면서 man1이 가리키던
}                   // heap영역의 메모리 공간 반환. 디폴트 대입연산자를 쓸 경우, man2가 비어있는 공간을 가리키는 오류가 발생
