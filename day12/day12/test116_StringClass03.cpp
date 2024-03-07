// file : test115_StringClass03.cpp
// date : 240307
// desc : 문자열 처리 클래스의 정의(p.508~514)

#include <iostream>
#include <string>
using namespace std;

class String
{
private:
	int len;
	char* str;
public:
	String();
	String(const char* s);
	String(const string& s);
	~String();
	String& operator= (const String& s);
	String& operator+=(const String& s);
	bool operator ==(const String& s);
	String operator+ (const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};

String::String()	// 디폴트 생성자
{
	len = 0;
	str = NULL;
}

String::String(const char* s)	// 문자열을 인자로 전달받는 생성자 정의
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)	// 깊은 복사를 하는 복사 생성자 정의
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()				// 메모리 영역을 반환하는 소멸자 정의
{
	if (str != NULL)
		delete[]str;
}

String& String::operator= (const String& s)		// 대입연산자 오버로딩
{
	if (str != NULL)
		delete[]str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s)		// += 연산자의 오버로딩
{
	len += (s.len - 1);
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcpy(tempstr, s.str);

	if (str != NULL)
		delete[]str;
	str = tempstr;
	return *this;
}

bool String::operator==(const String& s)		// 내용 비교하는 == 연산자의 오버로딩
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+ (const String& s)		// 결합된 문자열로 초기화된 객체를 반환하는  + 연산자의 오버로딩
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcpy(tempstr, s.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

ostream& operator<< (ostream& os, const String& s)	// 콘솔 출력이 가능하도록 << 연산자 오버로딩
{
	os << s.str;
	return os;
}

istream& operator>> (istream& is, String& s)		// 콘솔 입력이 가능하도록 >> 연산자 오버로딩
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}