// file : test56_ReturnObjCopyCon.cpp
// date : 240228
// desc : 객체를 반환하되, 참조형으로 반환하지 않는 경우

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	SoSimple& AddNum(int n)
	{
		num += n;	// num = num + n, num = 7 + 30
		return *this;	// 문장을 실행하는 객체 자신을 반환. 반환형이 참조형이니 참조값이 반환됨
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) // 인자의 전달과정에서 복사 생성자가 호출됨
{
	cout << "return 이전" << endl;
	return ob;	// ob 객체를 반환. 참조형이 아니므로 ob객체의 복사본이 만들어지면서 반환 -> 복사생성자가 추가로 호출됨
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();	// SimpleFuncObj 함수가 반환한 객체 ob를 대상으로 AddNum함수를 호출하고, 이어서 AddNum 함수가 반환하는 참조값을 대상으로 ShowData 함수를 호출
	obj.ShowData();								// SimpleFuncObj(obj)에서 반환받은 ob객체는 지역변수이기 때문에 SimpleFuncObj함수를 벗어나면 사라짐. 
	return 0;									// 이때문에 ob객체를 복사한 이름없는 임시객체를 생성(복사생성자 호출)하여 이후의 함수들을 사용
}