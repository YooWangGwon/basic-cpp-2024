// file : test30_1_Point.h
// date : 240226
// desc : ����Ʈ Ŭ���� ����

#ifndef __POINT_H_
#define __POINT_H_ // �ߺ��Ǵ� ���¸� ���� ���� ���

class Point // Ŭ���� ����
{
private:
	int x; // ������ ���ȭ�ϱ� ���ؼ��� ���� �տ� const�� ���δ�.
	int y;

public: // �ܺο��� ����������� ���������� ����� �� ���� ������ ������ ���� GET�� ������ ���� SET�� ����Ͽ� �������� ����Ѵ�.
	bool InitMembers(int xpos, int ypos);
	int GetX() const; // ������ �Լ� 1 : private���� ����� ��������� Ŭ���� �ܺο����� ������� ������ �������� ���ǵǴ� �Լ�
	int GetY() const; // const�� �Լ� �ڿ� ������ �Լ��� ���ȭ�� -> �Լ� �������� ��������� ����� ���� �������� �ʰڴٴ� ��
					  // const�� �տ� ������ ��°��� ���ȭ
	bool SetX(int xpos); // ������ �Լ� 2
	bool SetY(int ypos); // ������ �ʿ����� ������, �ʿ��� �� �ִٰ� �ǴܵǴ� �Լ� -> bool SetX(int xpos), bool SetY(int ypos)
};
#endif