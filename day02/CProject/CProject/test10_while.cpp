// file : test10_while.cpp
// date : 20240221
// desc : �ݺ���� while

#include <iostream>

using namespace std;

int main()
{	
	int i = 1;
	int sum = 0;

	while (i <= 100) {
		
		sum += i; // sum = sum + 1
		i++; // for���� �ٸ��� �������� ���� ���������
		if (i == 11) break;
	}

	cout << sum << endl;

	return 0;
}