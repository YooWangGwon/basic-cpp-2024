// file : test30_2_Point.cpp
// date : 240226
// desc : 포인트 클래스 함수 정의

#include <iostream>
#include "test30_1_Point.h"
using namespace std;

bool Point::InitMembers(int xpos, int ypos) // Point 클래스의 멤버함수인 InitMembers의 정의
{
	if (xpos < 0 || ypos < 0)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const // 엑세스 함수 : private으로 선언된 멤버변수를 클래스 외부에서의 멤버변수 접근을 목적으로 정의되는 함수
{
	return x;
}

int Point::GetY() const
{
	return y;
}

bool Point::SetX(int xpos)
{
	if (0 > xpos || xpos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	y = ypos;
	return true;
}