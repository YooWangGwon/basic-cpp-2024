// file : test30_4_Rectangle.cpp
// date : 240226
// desc : Rectangle Ŭ���� �Լ� ����

# include <iostream>
# include "test30_3_Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{
	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
	{
		cout << "�߸��� ��ġ���� ����" << endl;
		return false;
	}
	upLeft = ul;
	lowRight = lr;
	return true;
}

void Rectangle::ShowRecInfo() const
{
	cout << "�� ���: " << '[' << upLeft.GetX() << ",";
	cout << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ�: " << '[' << lowRight.GetX() << ",";
	cout << lowRight.GetY() << ']' << endl;
}