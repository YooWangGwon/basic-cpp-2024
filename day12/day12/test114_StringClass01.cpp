// file : test114_StringClass01.cpp
// date : 240307
// desc : ǥ�� string Ŭ����(p.506~508)

# include <iostream>
# include <string>
using namespace std;

int main(void)
{
	string str1 = "I like ";
	string str2 = "string class";
	string str3 = str1 + str2;	// string ��ü�� ���������� ����

	cout << str1 << endl;	// string Ŭ������ << �����ڿ� ���ؼ��� �����ε� �Ǿ�����
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;			// ���ڿ� str1�� ���� ���ڿ� str2�� ���ٿ� ������ "���� ���ڿ�!"�� ����� ���� Ȯ��
	if (str1 == str3)
		cout << "���� ���ڿ�!" << endl;
	else
		cout << "�������� �ʴ� ���ڿ�!" << endl;

	string str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;			// string Ŭ������ >> �����ڿ� ���ؼ��� �����ε� �Ǿ�����
	cout << "�Է��� ���ڿ�: " << str4 << endl;
	return 0;
}