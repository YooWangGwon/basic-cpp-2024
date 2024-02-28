// file : test62_MyFriendFunction.cpp
// date : 240228
// desc : 함수의 friend 선언(p.251~254)

# include <iostream>
using namespace std;

class Point;	// 18행, 19행을 컴파일 하기 위한 클래스 선언

class PointOP
{
private:
	int opcnt;
public:
	PointOP() : opcnt(0)
	{ }

	Point PointAdd(const Point&, const Point&);	// 포인트 타입 객체의 참조 2개를 입력받는 함수
	Point PointSub(const Point&, const Point&);	// 함수 선언에서는 매개변수명을 생략가능하나 매개변수 타입은 생략할 수 없다.
	~PointOP()
	{
		cout << "Operation times: " << opcnt << endl;
	}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{  }
	friend Point PointOP::PointAdd(const Point&, const Point&);	// PointOP 클래스의 멤버함수 PointAdd에 대해 friend 선언
	friend Point PointOP::PointSub(const Point&, const Point&);	// PointOP 클래스의 멤버함수 PointSub에 대해 friend 선언
	friend void ShowPointPos(const Point&);	// ShowPointPos에 대해 friend 선언
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)	// 함수 정의에서는 매개변수명을 생략해선 안된다.
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);	// Point클래스의 friend로 선언되었기 때문에 private 멤버에 접근이 가능
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);	// Point클래스의 friend로 선언되었기 때문에 private 멤버에 접근이 가능
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	return 0;
}

void ShowPointPos(const Point& pos)
{
	cout << "x: " << pos.x << ",";	// Point클래스의 friend로 선언되었기 때문에 private 멤버에 접근이 가능
	cout << "y: " << pos.y << endl;	// Point클래스의 friend로 선언되었기 때문에 private 멤버에 접근이 가능
}
