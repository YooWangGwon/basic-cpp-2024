// file : test89_FirstOperationOverloading.cpp
// date : 240305
// desc : 멤버함수에 의한 연산자 오버로딩

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)	: xpos(x), ypos(y)// 입력이 전달안되면 Default값(x=0, y=0)으로 초기화
	{	}
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point operator+(const Point& ref)	// operator+ 함수 : 연산자 오버로딩의 형식 'operator'+ '연산자', 참조하는 값이 변동되지 않도록 const를 사용.
	{									// 객체간 덧셈 결과를 기반으로 객체를 생성하기 위한 함수
		Point pos(xpos + ref.xpos, ypos + ref.ypos);	// 새로운 Point타입 객체 생성, 개발자가 만든 자료형에 더하기 기능을 구현하기 위해 연산자 오버로딩을 활용
		return pos;										// pos1의 x값에 pos2의 x값을 더하고 pos1의 y값에 pos2의 y값을 더하여 새로운 Point 타입 객체를 생성 
	}
	Point operator-(const Point& ref)	// 객체간 뺄셈 결과를 기반으로 객체를 생성하기 위한 함수
	{
		Point pos(xpos - ref.xpos, ypos - ref.ypos);
		return pos;	
	}
	Point operator*(const Point& ref)	// 객체간 곱셈 결과를 기반으로 객체를 생성하기 위한 함수
	{
		Point pos(xpos * ref.xpos, ypos * ref.ypos);
		return pos;
	}
	Point operator/(const Point& ref)	// 객체간 나눗셈 결과를 기반으로 객체를 생성하기 위한 함순
	{
		Point pos(xpos / ref.xpos, ypos / ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);	// pos1 객체로 operator+ 함수를 호출하면서 인자로 pos2를 전달하여 생긴 임시객체를 pos3에 대입
	Point pos4 = pos2.operator-(pos1);
	Point pos5 = pos1.operator*(pos2);
	Point pos6 = pos2.operator/(pos1);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	pos6.ShowPosition();
	return 0;
}