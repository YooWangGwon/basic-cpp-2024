#include <iostream>
#include <typeinfo>
using namespace std;

class Myclass
{
private:
    int x;
public:
    Myclass(int a=0) : x(a)
    {  }

    void print()
    {
        cout << x << endl;
    }

    friend Myclass& operator+(const Myclass& ref1, const Myclass& ref2); // a+b로 연산자를 사용하기 위한 전역함수 선언
    friend Myclass& operator-(const Myclass& ref1, const Myclass& ref2);
    friend Myclass& operator/(const Myclass& ref1, const Myclass& ref2);

};

Myclass& operator+(const Myclass& ref1, const Myclass& ref2)
{
    Myclass ref(ref1.x + ref2.x);
    return ref;
}

Myclass& operator-(const Myclass& ref1, const Myclass& ref2)
{
    Myclass ref(ref1.x - ref2.x);
    return ref;
}

Myclass& operator/(const Myclass& ref1, const Myclass& ref2)
{
    Myclass ref(ref1.x / ref2.x);
    return ref;
}

int main(void)
{
    Myclass a(10);
    a.print();          // value : 10

    Myclass b(a);
    b.print();          // value : 10

    Myclass c = b;
    c.print();          // value : 10

    Myclass d = a + b + 5;
    d.print();          // value : 25

    Myclass e = a - b + c;
    e.print();          // value : 10

    Myclass f1 = (a + b) / c;    
    f1.print();          // value : 2

    Myclass f2 = a + b / c;
    f2.print();          // value : 11

    Myclass g = (a + b) / 5;
    g.print();          // value : 4

    Myclass h = 100/a;
    h.print();          // value : 10   -> 계산되는 순간 const로 인해 100이 임시객체로 취급되면서 정수와 객체간 계산이 가능해짐

    Myclass i(5);
    Myclass j = a / i;
    j.print();          // value : 2

    cout << typeid(100).name() << endl;

    return 0;
}