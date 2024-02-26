// file : test29_InformationHiding
// date : 240226
// desc : 정보은닉의 이해(p.150~153)

#include <iostream>
using namespace std;

class Point // Point 클래스의 멤버변수 x와 y는 public으로 선언되어 어디서든 접근이 가능(멤버 함수는 없다)
{
public:
	int x; // x좌표의 범위는 0이상 100이하
	int y; // y좌표의 범위는 0이상 100이하
};

class Rectangle // 두 개의 Point 객체를 멤버변수로 두었다. (Class는 Type이기 때문에 가능)
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "좌 상단: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "우 하단: " << '[' << lowRight.x << ",";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main(void)
{
	Point pos1 = { -2,4 }; // 직사각형을 표현할 Point 타입의 pos1 객체 생성
	Point pos2 = { 5,9 };  // 직사각형을 표현할 Point 타입의 pos2 객체 생성
	Rectangle rec = { pos2, pos1 }; // 바로 위에서 생성한 Point객체를 이용해 Rectangle타입의 rec 객체를 생성 및 초기화
	rec.ShowRecInfo(); 
	return 0;
}

/*
점의 좌표는 0이상 100이하가 되어야 하는데, 그렇지 못한 Point객체가 있따
직사각형을 의미하는 Rectangle 객체의 좌상단 좌표값이 우 하단 좌표값보다 크다
*/