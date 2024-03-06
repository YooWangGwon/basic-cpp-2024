# include <iostream>
// using namespace std;

class MyClass
{
private:
	int* ptr;
public:
	MyClass(int p) : ptr(new int[100]) // int 타입의 방 100개의 메모리 공간을 할당받음
	{	
		printf("생성자 호출\n");
	}
	~MyClass()
	{
		printf("소멸자 호출\n");
		delete[] ptr;
	}
};

int main(void)
{
	MyClass *m1 = new MyClass(10); // new 연산자를 통해 heap 영역에 MyClass 타입 객체 생성 -> 소멸이 안됨!
	std::cout << "==================================" << std::endl;
	std::unique_ptr<MyClass>m2(new MyClass(20));

	return 0;
}