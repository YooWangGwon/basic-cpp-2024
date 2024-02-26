// file : test29_InformationHiding
// date : 240226
// desc : ���������� ����(p.150~153)

#include <iostream>
using namespace std;

class Point // Point Ŭ������ ������� x�� y�� public���� ����Ǿ� ��𼭵� ������ ����(��� �Լ��� ����)
{
public:
	int x; // x��ǥ�� ������ 0�̻� 100����
	int y; // y��ǥ�� ������ 0�̻� 100����
};

class Rectangle // �� ���� Point ��ü�� ��������� �ξ���. (Class�� Type�̱� ������ ����)
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "�� ���: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "�� �ϴ�: " << '[' << lowRight.x << ",";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main(void)
{
	Point pos1 = { -2,4 }; // ���簢���� ǥ���� Point Ÿ���� pos1 ��ü ����
	Point pos2 = { 5,9 };  // ���簢���� ǥ���� Point Ÿ���� pos2 ��ü ����
	Rectangle rec = { pos2, pos1 }; // �ٷ� ������ ������ Point��ü�� �̿��� RectangleŸ���� rec ��ü�� ���� �� �ʱ�ȭ
	rec.ShowRecInfo(); 
	return 0;
}

/*
���� ��ǥ�� 0�̻� 100���ϰ� �Ǿ�� �ϴµ�, �׷��� ���� Point��ü�� �ֵ�
���簢���� �ǹ��ϴ� Rectangle ��ü�� �»�� ��ǥ���� �� �ϴ� ��ǥ������ ũ��
*/