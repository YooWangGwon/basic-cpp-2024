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
    friend ostream& operator<<(ostream& os, const Point& ref);  // << ������ �����ε��� Point�� x���� y���� ������ �� �ֵ��� friend ����
    friend Point& operator+(int num, const Point& ref);
};
ostream& operator<<(ostream& os, const Point& ref)  // ��ü ����� ���� << ������ �����ε�
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

