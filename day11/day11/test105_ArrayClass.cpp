# include<iostream>
#include<cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		printf("생성자 호출\n");
		arr = new int[len];			// heap  영역에 메모리 공간 할당
	}
	int& operator[] (int idx)
	{
		printf("[]연산자 함수 호출\n");
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;	// 접근할 수 없는 범위일때 출력
			BoundCheckIntArray::~BoundCheckIntArray();	// 강제종료 되기 전 메모리 공간을 반환. 이 코드를 입력하지 않으면 메모리가 반환되지 않고 강제종료됨
			exit(1);	// 강제 종료
		}
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		printf("소멸자 호출\n");
		delete[]arr;	// 메모리 공간 반환
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)	// 5번 실행
		arr[i] = (i + 1) * 11;	// 0번방 부터 시작해서 값을 11씩 높이면서 넣고 있음
	for (int i = 0; i < 6; i++)	// 6번 실행
		cout << arr[i] << endl;	// 6번째에서 "Array index out of bound exception" 출력

	return 0;
}