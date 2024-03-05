// file : test92_Add.cpp
// date : 240305
// desc : 

/*
객체를 더하는 add 멤버함수
*/
# include <iostream>
using namespace std;


class Point
{
private:
	int x, y;
public:
	Point(int ax = 0, int ay = 0) : x(ax), y(ay)
	{
		cout << "Operator" << endl;
	}
	Point add(const Point& other)
	{
	Point pos(x + other.x, y + other.y);	// 새로운 Point타입 객체 생성, 개발자가 만든 자료형에 더하기 기능을 구현하기 위해 연산자 오버로딩을 활용
	return pos;
	}
	void ShowPoint()
	{
		cout << '[' << x << "," << y << ']' << endl;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.add(pos2);
	pos3.ShowPoint();

	return 0;
}