# include <iostream>
# include <string>
using namespace std;

class Point
{
private:
    int x, y;
public:
    Point(int numx = 0, int numy = 0) : x(numx), y(numy)
    { }
    void viewPoint() const
    {
        std::cout << '[' << x << "," << y << ']' << std::endl;
    }
    Point& operator+(const Point& ref) const
    {
        Point result(x + ref.x, y + ref.y);
        return result;
    }
    Point& operator+(int num) const
    {
        Point result(x + num, y + num);
        return result;
    }
    friend ostream& operator<<(ostream& os, const Point& ref);  // << 연산자 오버로딩이 Point의 x값과 y값에 접근할 수 있도록 friend 선언
    friend Point& operator+(int num, const Point& ref);
};
ostream& operator<<(ostream& os, const Point& ref)  // 객체 출력을 위한 << 연산자 오버로딩
{
    os << '[' << ref.x << "," << ref.y << ']' << endl;
    return os;
}

Point& operator+(int num, const Point& ref)
{
	Point result(num + ref.x, num + ref.y);
	return result;
}

int main (void)
{
	Point a(10, 20);
	Point b(30, 40);
	Point c = a + b;
	Point d = a + 100;
	Point e = 100 + a;

	d.viewPoint();
	e.viewPoint();

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
}

