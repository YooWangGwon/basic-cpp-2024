// file : test25_fileDiv.cpp
// date : 240223
// desc : ����Լ� ���� �ǽ�


# include <iostream>
# include <cstring>
# include "test25_fileDiv.h"
/*
AClass::AClass(int anum) { // ������ : �ϳ��� ���� �Է¹޾� �ʵ尪�� �ʱ�ȭ�ϴ� ���� ���
	num = anum;
}

void AClass::Alnfo() {
	std::cout << "A::num" << num << std::endl;
}
*/
Human::Human(const char* Hname, int Hage, const char* Hjob) 
{
	strcpy(name, Hname);
	age = Hage;
	strcpy(job, Hjob);;
}

void Human::humanInfo() {
	std::cout << "���� " << age << "���� " << job <<" "<< name << "�Դϴ�." << std::endl;
}

int main()
{
	/*
	AClass a(10); // a��� �Լ��� ȣ���ϸ鼭 10�� �Է� -> AClass�� �ִ� ������(num=anum)�� ȣ���
	a.Alnfo();
	*/

	Human h("ȫ�浿", 25, "���");
	h.humanInfo();
		return 0;
}
