// file : test90_GFunctionOverloading.cpp
// date : 240305
// desc : �����Լ��� ���� ������ �����ε�

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
	friend Point operator+(const Point& pos1, const Point& pos2);	// operator+ �Լ������� Point Ŭ������ private ������ ������ ����ϱ� ���� friend ������ ��
};

Point operator+(const Point& pos1, const Point& pos2)				// + �����ڸ� �����Լ� ���·� �����ε�. friend ���� ���� Point Ŭ������ private ����� xpos�� ypos�� ������ ����
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;	// �����Լ��� ����Ǿ� �ֱ� ������ ��ü�� ���� �Լ��� ȣ���� �ʿ䰡 ����.
	Point pos4 = operator+(pos2, pos3);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	return 0;
}