// file : 221_04
// date : 20240221
// desc : 반복제어문 - for

#include <iostream>

using namespace std;

// int sum; -> 전역변수로 선언할 경우 자동으로 0으로 초기화되지만 데이터가 오염(손상)될 확률이 높기 때문에 가급적이면 사용하지 않는 것이 좋다.

int main() 
{
	int sum=0; // sum의 역할 : 누적된 변수들을 저장해주는 역할 -> 초기화 절차가 필수!

	for (int i = 1; i <= 100; i++) {
		// sum += i;
		sum = sum + i;
	}
	cout << sum << endl;

	return 0;
}