// file : test05_stringIO.cpp
// date : 20240221
// desc : �迭����� ���ڿ� �����(p.21)

#include <iostream>

int main(void)
{
	char name[100];
	char lang[200];

	std::cout<<"�̸��� �����Դϱ�?";
	std::cin >> name;

	std::cout << "�����ϴ� ���α׷��� ���� �����ΰ���?";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�.\n";
	std::cout << "���� �����ϴ� ���� " << lang << "�Դϴ�." << std::endl;
	return 0;

}