// file : test120_Specialization.cpp
// date : 240307
// desc : �Լ� ���ø��� Ư��ȭ

# include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)	// ��Ȳ ������
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;			// ���� ũ��
	cout << Max('T', 'Q') << endl;			// ���ĺ� ����
	cout << Max(3.5, 7.5) << endl;			// �Ǽ� ũ��
	cout << Max("Simple", "Best") << endl;
	return 0;
}