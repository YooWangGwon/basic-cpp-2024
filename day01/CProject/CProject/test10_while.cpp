// file : test10_while.cpp
// date : 20240221
// desc : 반복제어문 while

#include <iostream>

using namespace std;

int main()
{	
	int i = 1;
	int sum = 0;

	while (i <= 100) {
		
		sum += i; // sum = sum + 1
		i++; // for문과 다르게 증감식을 따로 적어줘야함
		if (i == 11) break;
	}

	cout << sum << endl;

	return 0;
}