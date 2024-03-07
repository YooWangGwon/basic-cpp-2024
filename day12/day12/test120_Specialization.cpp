// file : test120_Specialization.cpp
// date : 240307
// desc : 함수 템플릿의 특수화

# include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)	// 상황 연산자
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;			// 정수 크기
	cout << Max('T', 'Q') << endl;			// 알파벳 순서
	cout << Max(3.5, 7.5) << endl;			// 실수 크기
	cout << Max("Simple", "Best") << endl;
	return 0;
}