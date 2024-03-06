#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
	
	void* operator new(size_t size)
	{
		cout << "operator new: " << size << endl;
		void* adr = new char[size];		// 바이트 단위로 필요한 공간을 할당, 할당에 사용되는 크기 정보(size)는 컴파일러가 전달함.	-> 메모리 공간를 먼저 할당받고 난 다음 생성자 호출
		return adr;
	}
	void operator delete(void* adr)	// delete 연산자 오버로딩
	{
		cout << "operator delete()" << endl;
		delete[]adr;	// 배열 삭제를 위한 delete문 구성. char 형으로 할당된 메모리 공간을 해제
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);
	cout << *ptr;	// *ptr : 참조연산자 -> 데이터 값
	delete ptr;
	return 0;
}