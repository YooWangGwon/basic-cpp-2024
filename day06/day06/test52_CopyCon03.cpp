// file : test52_CopyCon03.cpp
// date : 240227
// desc : ���������3

#include <iostream>
using namespace std;

class AA
{
	int a;
	int b;
public:
	AA(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void AAInfo() {
		cout << a << " " << b << endl;
	}
	AA(const AA& copy){
		cout << "��������� ȣ��" << endl;
		this->a = copy.a; // ���������� ���� �ʵ忡 ����
		this->b = copy.b;
	}
};

int main(void)
{
	AA obj1(23, 24);
	obj1.AAInfo();

	AA obj2(obj1);
	obj2.AAInfo();

	return 0;
}