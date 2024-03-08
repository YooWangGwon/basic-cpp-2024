// file : test123_test123_ClassTemFunDef.cpp
// date : 240308
// desc : 클래스 템플릿의 선언과 정의의 분리

#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{ }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << "," << ypos << ']' << endl;
}

int main(void)
{
	Point<int> pos1(3, 4);			// Point<int> 템플릿 클래스
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);	// Point<double> 템플릿 클래스 
	pos2.ShowPosition();

	Point<char>pos3('P', 'F');		// Point<char> 템플릿 클래스
	pos3.ShowPosition();
	return 0;
}