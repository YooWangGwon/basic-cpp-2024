// file : test61_MyFriendClass.cpp
// date : 240228
// desc : Ŭ������ friend ����

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Girl;	// Girl�̶�� �̸��� Ŭ������ �̸��� �˸�

class Boy
{
private:
	int height;
	friend class Girl;	// Girl class�� ���� friend ����
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
	friend class Boy;	// Boy class�� ���� friend ����
};

void Boy::ShowYourFriendInfo(Girl& frn)	// ����Լ��� ����ο� ���Ǻθ� �и� 1:����Լ��� �Ҽ� �ۼ� �ʼ�
{
	cout << "Her phone number : " << frn.phNum << endl;	// Girl�� Private ��������� phNum�� ����
}

void Girl::ShowYourFriendInfo(Boy& frn)	// ����Լ��� ����ο� ���Ǻθ� �и� 2:����Լ��� �Ҽ� �ۼ� �ʼ�
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