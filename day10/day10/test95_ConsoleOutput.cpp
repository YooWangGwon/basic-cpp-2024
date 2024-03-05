#include <iostream>
namespace mystd     // cout과 endl을 직접 구현하기 위해서 선언한 이름공간
{
    using namespace std;    // 이름공간 mystd 내에서 이루어진 것으로 지역내에서만 유효한 선언

    class ostream
    {
    public:
        void operator<< (const char* str)
        {
            printf("%s", str);
        }
        void operator<< (char str)
        {
            printf("%c", str);
        }
        void operator<< (int num)
        {
            printf("%d", num);
        }
        void operator<< (double e)
        {
            printf("%g", e);
        }
        void operator<< (ostream& (*fp)(ostream& ostm))
        {
            fp(*this);
        }
    };

    ostream& endl(ostream& ostm)    // endl은 함수의 형태를 가진다
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

    cout << "Simple String";
    cout << endl;
    cout << 3.14;
    cout << endl;
    cout << 123;
    endl(cout);
    return 0;
}