// file : test30_3_Rectangle.h
// date : 240226
// desc : Rectangle Ŭ���� ����

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "test30_1_Point.h"

class Rectangle
{
private:
	Point upLeft;
	Point lowRight;
public:
	bool InitMembers(const Point& ul, const Point& lr);
	void ShowRecInfo() const;
};

#endif