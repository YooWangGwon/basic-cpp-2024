// file : test91_OnePondOverloading
// date : 240305
// desc : ���׿�����

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point& operator++()	// ��� �Լ��� ���� ���׿����� �����ε�
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point& ref);
};

Point& operator--(Point& ref)	// ���� �Լ��� ���� ���׿����� �����ε�
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main(void)
{
	Point pos1(1, 2);
	++pos1;
	pos1.ShowPosition();
	--pos1;
	pos1.ShowPosition();

	++(++pos1);
	pos1.ShowPosition();
	--(--pos1);
	pos1.ShowPosition();
	return 0;
}