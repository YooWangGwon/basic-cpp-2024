// file : test94_PointMultipleOperation.cpp
// date : 240305
// desc : 교환법칙(p.425~429)

#include <iostream>
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
        cout << '[' << xpos << "," << ypos << ']' << endl;
    }
    Point operator*(int times)  // 곱셈 연산자 오버로딩 -> Point객체와 정수간 곱셈이 가능해짐
    {
        Point pos(xpos * times, ypos * times);  // Pos객체 생성
        return pos; // Pos 객체 반환
    }
    friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)  //  cpy = 4 * pos가 성립하기 위한 함수 추가
{
    return ref * times; // ref * times -> ref.operator*(times)
}

int main(void)
{
    Point pos(1, 2);
    Point cpy;

    cpy = pos * 3;  //  pos.operator*(3)으로 해석
    cpy.ShowPosition();

    cpy = pos * 3 * 2;  // 3을 곱했을 때 반환되는 객체를 대상으롱 다시 2를 곱하는 연산
    cpy.ShowPosition();

    cpy = 4 * pos;
    cpy.ShowPosition();

    cpy = 2 * pos * 3;
    cpy.ShowPosition();
    return 0;
}