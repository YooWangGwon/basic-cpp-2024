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
		std::cout << '(' << x << "," << y << ')' << std::endl;
	}
	Point& operator+(const Point&ref) const
	{
		Point result(x + ref.x, y + ref.y);
		return result;
	}
	Point& operator+(int num) const
	{
		Point result(x + num, y + num);
		return result;
	}
	void operator<<

	friend	Point& operator+(int num, const Point& ref);
};

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

	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
}

