// file : test50_CopyCon01.cpp
// date : 240227
// desc : 복사생성자

# include <iostream>
using namespace std;

/*복사 생성자 : 객체를 복사할 때 호출되는 생성자
				따라서 복사할 객체를 입력으로 가져야하는데 이때 원본 객체의 참조를 입력으로 받아야한다.
				(참조형태로 입력을 받는 이유:기존에 있던 객체를 이용하여 메모리를 추가적으로 할당할 필요 없음. 객체를 선언하는 형태로 매개변수를 사용하게되면 복사생성자가 무한히 반복됨)
*/

class A
{
public:
	A() {
		cout << "디폴트 생성자 호출" << endl;
	}
	A(int n)
	{
		cout << "A(int n)생성자 호출" << endl;
	}
	A(const A& r) // 복사생성자 , const: 원본에 해당되는 값이 변경되면 안되기 때문.
	{
		cout << "A(const A& r)생성자 호출" << endl;
	}
};

void func(int a) {

}

int main(void)
{
	A obj1;			// 디폴트 생성자로 객체 생성
	A obj2(10);		// 입력 하나를 가지는 생성자 호출
	A obj3(obj2);	// 복사생성자 호출
	return 0;
}