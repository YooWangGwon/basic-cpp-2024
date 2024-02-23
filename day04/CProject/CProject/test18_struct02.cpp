// file : test18_struct02.cpp
// date : 240223
// desc : C++타입 구조체

// C++ 타입의 구조체 : 구조체 멤버로 멤버 변수와 멤버 함수를 가진다.

# include<iostream>

typedef struct human {
	char name[20];
	int age;
	char job[20];

	void showhuman() // 멤버함수 : 기능을 담당. 구조체 안에 있는 함수이기 때문에 따로 입력을 받을 필요가 없다.
	{
		printf("name : %s, age : %d, job : %s\n", name, age, job); // 구조체 안에 있는 함수이기 때문에 h.name이 아닌 name으로 변경
	}
}Human; // 앞으로 human 구조체를 Human으로 사용하겠다.

int main()
{
	int a;
	human h1 = { "홍길동",50,"의적" }; //Human 타입의 변수를 선언하고 초기화를 시킨다.
	h1.showhuman();

	return 0;
}
