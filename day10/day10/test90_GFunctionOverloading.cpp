// file : test90_GFunctionOverloading.cpp
// date : 240305
// desc : 전역함수에 의한 연산자 오버로딩

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);	// operator+ 함수에대해 Point 클래스의 private 영역의 접근을 허용하기 위해 friend 선언을 함
};

Point operator+(const Point& pos1, const Point& pos2)				// + 연산자를 전역함수 형태로 오버로딩. friend 선언에 의해 Point 클래스의 private 멤버인 xpos와 ypos에 접근이 가능
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;	// 전역함수로 선언되어 있기 때문에 객체를 통해 함수를 호출할 필요가 없다.
	Point pos4 = operator+(pos2, pos3);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	return 0;
}