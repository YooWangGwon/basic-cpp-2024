// file : test115_StringClass03.cpp
// date : 240307
// desc : ���ڿ� ó�� Ŭ������ ����(p.508~514)

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

String::String()	// ����Ʈ ������
{
	len = 0;
	str = NULL;
}

String::String(const char* s)	// ���ڿ��� ���ڷ� ���޹޴� ������ ����
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)	// ���� ���縦 �ϴ� ���� ������ ����
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()				// �޸� ������ ��ȯ�ϴ� �Ҹ��� ����
{
	if (str != NULL)
		delete[]str;
}

String& String::operator= (const String& s)		// ���Կ����� �����ε�
{
	if (str != NULL)
		delete[]str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s)		// += �������� �����ε�
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

bool String::operator==(const String& s)		// ���� ���ϴ� == �������� �����ε�
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+ (const String& s)		// ���յ� ���ڿ��� �ʱ�ȭ�� ��ü�� ��ȯ�ϴ�  + �������� �����ε�
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcpy(tempstr, s.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

ostream& operator<< (ostream& os, const String& s)	// �ܼ� ����� �����ϵ��� << ������ �����ε�
{
	os << s.str;
	return os;
}

istream& operator>> (istream& is, String& s)		// �ܼ� �Է��� �����ϵ��� >> ������ �����ε�
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}