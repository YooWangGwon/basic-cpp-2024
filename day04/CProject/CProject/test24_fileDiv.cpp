# include <iostream>

class AClass {
private: // 속성은 public으로 하지 말것. 생략할 경우 자동적으로 private이 된다.
	int num;

public: // 접근 제어지시자:어디서든지 접근 가능
	AClass(int anum) { // 생성자 : 하나의 값을 입력받아 필드값에 초기화하는 것을 담당
		num = anum;
	}

	void Alnfo() {
		std::cout << "A::num" << num << std::endl;
	}
};

int main()
{
	AClass a(10); // a라는 함수를 호출하면서 10을 입력 -> AClass에 있는 생성자(num=anum)가 호출됨
	a.Alnfo();

	return 0;
}