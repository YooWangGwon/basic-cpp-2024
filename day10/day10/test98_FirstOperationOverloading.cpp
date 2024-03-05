#include <iostream>
using namespace std;

class First     // 대입연산자 X
{
private:
    int num1, num2;
public:
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    { }
    void ShowData() { cout << num1 << "," << num2 << endl; }
};

class Second    // 대입연산자 O
{
private:
    int num3, num4;
public:
    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
    { }
    void ShowData() { cout << num3 << "," << num4 << endl; }

    Second& operator=(const Second& ref)
    {
        cout << "Second &operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};

int main(void)
{
    First fsrc(111, 222);
    First fcpy;             // num1, num2는 기본값인 0으로 초기화됨.
    Second ssrc(333, 444);
    Second scpy;            // num3, num4는 기본값인 0으로 초기화됨.

    // First fcpy = fsrc    // '복사 생성자' 호출 

    fcpy = fsrc;            // 객체 생성하고 난 뒤에 복사하는 것이니 대입 연산자 호출. 오버라이딩 된 대입연산자가 없으므로 'Default(기본값) 대입 연산자(멤버대 멤버 대입)' 호출
                            // '디폴트 복사 생성자'와 유사함

    scpy = ssrc;            // 명시적으로 작성한 '대입 연산자' 호출


    fcpy.ShowData();
    scpy.ShowData();

    First fob1, fob2;
    Second sob1, sob2;
    fob1 = fob2 = fsrc;
    sob1 = sob2 = ssrc;

    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();
    return 0;
}