#include <iostream>
#include "test124_1_PointTemplate.h"
#include "test124_2_PointTemplate.cpp"	// 템플릿의 경우 정의 파일까지 함께 include 해줘야함
using namespace std;

int main(void)
{
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();
	return 0;
}