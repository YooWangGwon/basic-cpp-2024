// file : test62_MyFriendFunction.cpp
// date : 240228
// desc : �Լ��� friend ����(p.251~254)

# include <iostream>
using namespace std;

class Point;	// 18��, 19���� ������ �ϱ� ���� Ŭ���� ����

class PointOP
{
private:
	int opcnt;
public:
	PointOP() : opcnt(0)
	{ }

	Point PointAdd(const Point&, const Point&);	// ����Ʈ Ÿ�� ��ü�� ���� 2���� �Է¹޴� �Լ�
	Point PointSub(const Point&, const Point&);	// �Լ� ���𿡼��� �Ű��������� ���������ϳ� �Ű����� Ÿ���� ������ �� ����.
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
	friend Point PointOP::PointAdd(const Point&, const Point&);	// PointOP Ŭ������ ����Լ� PointAdd�� ���� friend ����
	friend Point PointOP::PointSub(const Point&, const Point&);	// PointOP Ŭ������ ����Լ� PointSub�� ���� friend ����
	friend void ShowPointPos(const Point&);	// ShowPointPos�� ���� friend ����
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)	// �Լ� ���ǿ����� �Ű��������� �����ؼ� �ȵȴ�.
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);	// PointŬ������ friend�� ����Ǿ��� ������ private ����� ������ ����
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);	// PointŬ������ friend�� ����Ǿ��� ������ private ����� ������ ����
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
	cout << "x: " << pos.x << ",";	// PointŬ������ friend�� ����Ǿ��� ������ private ����� ������ ����
	cout << "y: " << pos.y << endl;	// PointŬ������ friend�� ����Ǿ��� ������ private ����� ������ ����
}
