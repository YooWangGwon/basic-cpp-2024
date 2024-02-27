// file : test45_ObjArr2.cpp
// date : 240227
// desc : 객체 배열2

# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace  std;

class Human {
private:
	char name[30];
	int age;

public:
	Human(const char * myname, int age)
	{
		cout << "생성자 호출" << endl;
		strcpy(name, myname);
		this->age = age;
	}
	void HumanInfo()
	{
		cout << "이름: " << name << " ";
		cout << "나이: " << age << endl<<endl;
	}
	~Human()
	{
		cout << "소멸자 호출!" << endl;
	}
};

int main(void)
{
	Human h[3] = { Human("홍길동",50), Human("김철수",40), Human("김영희",30) }; //객체배열

	for (int i = 0; i < 3; i++)
		h[i].HumanInfo(); // i번째 방에 있는 객체의 정보를 출력

	Human* h1 = new  Human("가나다", 50); // Human 타입의 객체를 heap영역에서 생성하고 그 주소값을 Human 타입의 h1 포인터 변수에 저장
	h1->HumanInfo();					  // 애로우 연산자를 통해 포인터 변수 h1이 가리키는 Human타입의 객체에 접근하여 HumanInfo함수를 사용

	Human h2("라마바", 30); // Human타입의 객체 h2 생성
	h2.HumanInfo(); // 객체 h2에 접근하여 HumanInfo함수를 사용

	return 0;
}