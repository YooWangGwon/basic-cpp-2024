// file : test25_fileDiv.cpp
// date : 240223
// desc : 멤버함수 정의 실습


# include <iostream>
# include <cstring>
# include "test25_fileDiv.h"
/*
AClass::AClass(int anum) { // 생성자 : 하나의 값을 입력받아 필드값에 초기화하는 것을 담당
	num = anum;
}

void AClass::Alnfo() {
	std::cout << "A::num" << num << std::endl;
}
*/
Human::Human(const char* Hname, int Hage, const char* Hjob) 
{
	strcpy(name, Hname);
	age = Hage;
	strcpy(job, Hjob);;
}

void Human::humanInfo() {
	std::cout << "나는 " << age << "살인 " << job <<" "<< name << "입니다." << std::endl;
}

int main()
{
	/*
	AClass a(10); // a라는 함수를 호출하면서 10을 입력 -> AClass에 있는 생성자(num=anum)가 호출됨
	a.Alnfo();
	*/

	Human h("홍길동", 25, "백수");
	h.humanInfo();
		return 0;
}
