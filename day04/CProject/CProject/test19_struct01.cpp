// file : test19_struct01
// date : 240223
// desc : C타입 구조체


# include<stdio.h>

// C타입의 구조체 : 멤버 변수만 가진다

// 구조체  선언(C타입 기준)

typedef struct human {		// human 구조체(개발자가 만든 사용자 정의 자료형)
	char name[20]; // 속성;멤버변수: name, age, job
	int age;
	char job[20];
}Human; // 앞으로 human 구조체를 Human으로 사용하겠다.

void showhuman(Human h)
{
	printf("name : %s age : %d job : %s\n", h.name, h.age, h.job);
}


int main()
{
	int a;
	human h1 = { "홍길동",50,"의적" }; //Human 타입의 변수를 선언하고 초기화를 시킨다.
	showhuman(h1);

	return 0;
}
