// file : test119_PrimitiveFucTemplate.cpp
// date : 240307
// desc : �� �̻��� �ڷ��� ���ø�

#include <iostream>
using namespace std;

template <class T1, class T2>	// typename Ű���� ��� class Ű���� ���(�� �� ��밡��)
void ShowData(double num)
{
	cout << (T1)num << "," << (T2)num << endl;
}

int main(void)
{
	ShowData<char, int>(65);		// A,65	(ASCII �ڵ� 65 -> A)
	ShowData<char, int>(67);		// C,67	(ASCII �ڵ� 67 -> C)
	ShowData<char, double>(68.9);	// D,68.9	(ASCII �ڵ� 68 -> A)
	ShowData<short, double>(69.2);	// 69,69.2
	ShowData<short, double>(70.4);	// 70,70.4

	return 0;
}