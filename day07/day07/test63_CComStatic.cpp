// file : test63_CComStatic.cpp
// date : 240228
// desc : static변수(정적변수)

#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;	// 정적 데이터 영역에 cnt 변수의 공간 할당 -> 함수가 끝나도 함수만 사라지고 cnt 변수가 사라지지 않고 계속 사용 -> Current cnt : 1부터 10까지 출력됨 
	// int cnt = 0;	// 함수가 끝나면 cnt 변수가 사라짐 -> Current cnt : 1 출력이 10번 반복됨
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}