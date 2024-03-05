// file : test89_FirstOperationOverloading.cpp
// date : 240305
// desc : ����Լ��� ���� ������ �����ε�

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)	: xpos(x), ypos(y)// �Է��� ���޾ȵǸ� Default��(x=0, y=0)���� �ʱ�ȭ
	{	}
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point operator+(const Point& ref)	// operator+ �Լ� : ������ �����ε��� ���� 'operator'+ '������', �����ϴ� ���� �������� �ʵ��� const�� ���.
	{									// ��ü�� ���� ����� ������� ��ü�� �����ϱ� ���� �Լ�
		Point pos(xpos + ref.xpos, ypos + ref.ypos);	// ���ο� PointŸ�� ��ü ����, �����ڰ� ���� �ڷ����� ���ϱ� ����� �����ϱ� ���� ������ �����ε��� Ȱ��
		return pos;										// pos1�� x���� pos2�� x���� ���ϰ� pos1�� y���� pos2�� y���� ���Ͽ� ���ο� Point Ÿ�� ��ü�� ���� 
	}
	Point operator-(const Point& ref)	// ��ü�� ���� ����� ������� ��ü�� �����ϱ� ���� �Լ�
	{
		Point pos(xpos - ref.xpos, ypos - ref.ypos);
		return pos;	
	}
	Point operator*(const Point& ref)	// ��ü�� ���� ����� ������� ��ü�� �����ϱ� ���� �Լ�
	{
		Point pos(xpos * ref.xpos, ypos * ref.ypos);
		return pos;
	}
	Point operator/(const Point& ref)	// ��ü�� ������ ����� ������� ��ü�� �����ϱ� ���� �Լ�
	{
		Point pos(xpos / ref.xpos, ypos / ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);	// pos1 ��ü�� operator+ �Լ��� ȣ���ϸ鼭 ���ڷ� pos2�� �����Ͽ� ���� �ӽð�ü�� pos3�� ����
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