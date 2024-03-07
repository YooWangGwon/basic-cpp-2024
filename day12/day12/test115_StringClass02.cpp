// file : test115_StringClass02.cpp
// date : 240307
// desc : C�� C++�� ���ڿ�

/*
C - Style ���ڿ�
���ڿ��� �������� null ���ڰ� �ٴ´�.
*/


#include <iostream>
using namespace std;

int main()
{
	printf("===C - Style ���ڿ�===========================\n");

	int code = 97;
	cout << code << endl;
	cout << (char)code << endl;	// ascii �ڵ�ǥ���� 97�� a�� �ش��ϱ� ����

	cout << "==============================" << endl;
	char ary1[6] = { 'a','b','c','d','e' };		// ���� Ÿ���� �迭 ����
	cout << ary1 << endl;

	printf("==============================\n");
	char ary2[] = { 'a','b','c','\0','e' };	// '\0' = null ���� : ������ ���� �˷���
	cout << ary2 << endl;
	cout << sizeof(ary2) << endl;	// ��ü ������ ũ�� ��ȯ
	cout << strlen(ary2) << endl;	// null ���� �ձ����� ũ��

	printf("==============================\n");
	char str[] = "string";	// �ڵ����� �� ���� null ���ڰ� �ٴ´�. Stack(����)�� �����.
	cout << str << endl;
	cout << sizeof(str) << endl;	// 7 -> string�� null���ڰ� ���Ե� ũ��
	cout << strlen(str) << endl;	// 6 -> null ���� �ձ����� ũ��
	str[0] = 'S';
	cout << str << endl;			// String

	printf("==============================\n");
	const char* pstr = "STRING";	// char * �� ���� ��� error �߻�. Data Segment�� �����.
	cout << pstr << endl;
	cout << sizeof(pstr) << endl;	// 8 -> ������ ������ ũ�� : 64��Ʈ �ü�� �̱� ������ �ּ� ũ�Ⱑ 8byte
	cout << strlen(pstr) << endl;	// 6 -> null ���� �ձ����� ũ��
	int a = 100;
	int* pa = &a;
	cout << sizeof(pa) << endl;		// 64��Ʈ���� ��� �������� ũ��� 8byte
	// pstr[0] = 's';	// ���ڿ��� �����ͷ� ����ϴ� ���� ������ �Ұ��� 
						// -> ������ ������ ���� ����� STRING�� Data Segment�� ����Ǵµ� Data Segment�� ReadOnly�� Ư¡�� ������ ������ �Ұ����ϴ�.

	/*
	C++ - style : heap ������ ����
	*/
	printf("===C++ - Style ���ڿ�=========================\n");

	string s = "string";
	cout << s << endl;
	cout << sizeof(s) << endl;	// 40(byte) - �⺻���� string Ŭ���� ��ü�� ũ��
	// cout << strlen(s) << endl;	// const char * Ÿ���̱� ������ ��� �Ұ���
	cout << s.size() << endl;	// 6

	string s1 = "Yoo Wang Gwon";
	cout << s1 << endl;
	cout << sizeof(s1) << endl;	// 40(byte)
	cout << s1.size() << endl;	// 13 : ������ ����+���� ����

	return 0;
}