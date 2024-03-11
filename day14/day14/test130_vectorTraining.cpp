// file : test130_vectorTraining.cpp
// date : 2403011
// desc : vector 연습

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> v;
	int sum = 0;
	int a = 0;

	while (true)
	{
		cout << "정수를 입력하시오(0 종료) > ";
		cin >> a;
		if (!a)		// a값이 0이면
		{
			break;	// 종료
		}
		v.push_back(a);
		sum += a;
		cout << "평균값 : " << sum / v.size() << endl;
	}

	cout << "프로그램을 종료합니다.";

	return 0;
}

