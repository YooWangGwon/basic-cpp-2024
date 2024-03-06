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
		void* adr = new char[size];		// ����Ʈ ������ �ʿ��� ������ �Ҵ�, �Ҵ翡 ���Ǵ� ũ�� ����(size)�� �����Ϸ��� ������.	-> �޸� ������ ���� �Ҵ�ް� �� ���� ������ ȣ��
		return adr;
	}
	void operator delete(void* adr)	// delete ������ �����ε�
	{
		cout << "operator delete()" << endl;
		delete[]adr;	// �迭 ������ ���� delete�� ����. char ������ �Ҵ�� �޸� ������ ����
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
	cout << *ptr;	// *ptr : ���������� -> ������ ��
	delete ptr;
	return 0;
}