// file : test61_MyFriendClass.cpp
// date : 240228
// desc : 클래스의 friend 선언

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Girl;	// Girl이라는 이름이 클래스의 이름을 알림

class Boy
{
private:
	int height;
	friend class Girl;	// Girl class에 대한 friend 선언
public:
	Boy(int len) : height(len)
	{  }
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;	// Boy class에 대한 friend 선언
};

void Boy::ShowYourFriendInfo(Girl& frn)	// 멤버함수의 선언부와 정의부를 분리 1:멤버함수의 소속 작성 필수
{
	cout << "Her phone number : " << frn.phNum << endl;	// Girl의 Private 멤버변수인 phNum에 접근
}

void Girl::ShowYourFriendInfo(Boy& frn)	// 멤버함수의 선언부와 정의부를 분리 2:멤버함수의 소속 작성 필수
{
	cout << "His height : " << frn.height << endl;
}

int main(void)
{
	Boy boy1(170);
	Girl girl1("010-1234-5678");
	boy1.ShowYourFriendInfo(girl1);
	girl1.ShowYourFriendInfo(boy1);
	return 0;
}