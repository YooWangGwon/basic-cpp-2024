// file : test91_OnePondOverloading
// date : 240305
// desc : 단항연산자

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
	Point& operator++()	// 멤버 함수에 의한 단항연산자 오버로딩
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point& ref);
};

Point& operator--(Point& ref)	// 전역 함수에 의한 단항연산자 오버로딩
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