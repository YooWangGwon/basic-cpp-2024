// file : test30_2_Point.cpp
// date : 240226
// desc : ����Ʈ Ŭ���� �Լ� ����

#include <iostream>
#include "test30_1_Point.h"
using namespace std;

bool Point::InitMembers(int xpos, int ypos) // Point Ŭ������ ����Լ��� InitMembers�� ����
{
	if (xpos < 0 || ypos < 0)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const // ������ �Լ� : private���� ����� ��������� Ŭ���� �ܺο����� ������� ������ �������� ���ǵǴ� �Լ�
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
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	y = ypos;
	return true;
}