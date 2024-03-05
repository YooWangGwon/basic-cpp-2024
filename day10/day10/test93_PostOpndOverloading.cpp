// file : test93_PostOpndOverloading.cpp
// date : 240305
// desc : 전위증가와 후위증가의 구분(p.418~421)

# include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[]' << xpos << "," << ypos << ']' << endl;
    }
    Point& operator++()                     // 전위 증가
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    const Point operator++(int)             // 후위 증가 : 자신을 먼저 복사하고 증가, 매개변수의 선언에 int를 추가하여 후위 증가임을 명시 
    {   // 1. 현재의 객체를 복사하여 현재의 속성값을 유지시킨다. 복사본의 값이 변경되선 안되기 때문에 const로 선언
        const Point retobj(xpos, ypos);     // const Point retobj(*this);   -> 함수 내에서 retobj의 변경을 막겠다.
        // 2. 현재 객체의 속성값을 1씩 증가시킨다.
        xpos += 1;
        ypos += 1;
        // 3. 복사한 객체를 전달한다.
        return retobj;                      // 증가시키기 전의 자신을 복사한 것을 return
    }
    friend Point& operator--(Point& ref);
    friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)               // 전위 감소
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point& ref, int)     // 후위 감소 : 매개변수의 선언에 int를 추가하여 후위 증가임을 명시 
{
    const Point retobj(ref);    // 현재의 객체를 복사하고 변환되지않게 const 선언
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj;
}

int main(void)
{
    Point pos(3, 5);
    Point cpy;
    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy = pos++;
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}