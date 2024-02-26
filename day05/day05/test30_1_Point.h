// file : test30_1_Point.h
// date : 240226
// desc : 포인트 클래스 선언

#ifndef __POINT_H_
#define __POINT_H_ // 중복되는 형태를 막기 위해 사용

class Point // 클래스 선언
{
private:
	int x; // 변수를 상수화하기 위해서는 변수 앞에 const를 붙인다.
	int y;

public: // 외부에서 멤버변수들을 직접적으로 사용할 수 없기 때문에 참조를 위한 GET과 저장을 위한 SET를 사용하여 가져오고 사용한다.
	bool InitMembers(int xpos, int ypos);
	int GetX() const; // 엑세스 함수 1 : private으로 선언된 멤버변수를 클래스 외부에서의 멤버변수 접근을 목적으로 정의되는 함수
	int GetY() const; // const가 함수 뒤에 붙으면 함수를 상수화함 -> 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다는 뜻
					  // const가 앞에 붙으면 출력값을 상수화
	bool SetX(int xpos); // 엑세스 함수 2
	bool SetY(int ypos); // 당장은 필요하지 않지만, 필요할 수 있다고 판단되는 함수 -> bool SetX(int xpos), bool SetY(int ypos)
};
#endif