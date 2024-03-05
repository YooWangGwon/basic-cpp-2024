#include <iostream>

namespace mystd
{
    using namespace std; // C언어의 표준함수인 printf 함수의 호출을 위해 삽입

    class ostream
    {
    public:
        ostream& operator<< (char* str) // cout의 참조값을 반환하는 형태1
        {
                printf("%s", str);
                return *this;
        }
        ostream& operator<< (char str)  // cout의 참조값을 반환하는 형태2
        {
                printf("%c", str);
                return *this;
        }
        ostream& operator<< (int num)   // cout의 참조값을 반환하는 형태3
        {
                printf("%d", num);
                return *this;
        }
        ostream& operator<< (double e)  // cout의 참조값을 반환하는 형태
        {
                printf("%g", e);
                return *this;
        }
        ostream& operator<< (ostream& (*fp)(ostream& ostm))
        {
                return fp(*this);
        }
    };

    ostream& endl(ostream& ostm)
    {
        ostm << '\n';
        fflush(stdout);
        return ostm;
    }
    ostream cout;   // cout은 객체의 이름이며, 이 객체 내에서는 다양한 기본 자료형 데이터를 대상으로 << 연산자를 오버로딩 하고 있다.
}

int main(void)
{
    using mystd::cout;
    using mystd::endl;
    cout << 3.14 << endl << 123 << endl;
    return 0;
}