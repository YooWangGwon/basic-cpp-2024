// file : test92_Add.cpp
// date : 240305
// desc : 

/*
��ü�� ���ϴ� add ����Լ�
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
	Point pos(x + other.x, y + other.y);	// ���ο� PointŸ�� ��ü ����, �����ڰ� ���� �ڷ����� ���ϱ� ����� �����ϱ� ���� ������ �����ε��� Ȱ��
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