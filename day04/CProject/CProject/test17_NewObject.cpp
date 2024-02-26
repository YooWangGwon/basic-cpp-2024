// file : test17_NewObject
// date : 240223
// desc : NewObject(p.94~95)

# include <iostream>
# include <stdlib.h>
using namespace std;

class Simple // Ŭ���� : int, char�� ���� �� �ٸ� �ϳ��� Ÿ��
{
public:
	Simple() // ������ : Ŭ������ �̸��� ���� method
	{
		cout << "I'm simple constructor!" << endl;
	}
};

int main(void)
{
	cout << "case 1: ";
	Simple* sp1 = new Simple; // new�� ��ü�� �޸𸮸� �Ҵ���� �� ����(����� ���� �ڷ������ε� �޸𸮸� �Ҵ� ���� �� ����)
	// new �����ڸ� �̿��� heap�������� Simple�̶�� ������ �޸𸮸� �Ҵ��ϰ�, SimpleŸ�� sp1 ������ ������ stack�� ����� heap�� �޸� �ּҸ� ���� 
	//Aaa *ap = new Aaa;

	cout << "case 2: ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1); // malloc�� �⺻Ÿ��(int,char)���θ� �޸𸮸� �Ҵ����
	// malloc �����ڸ� �̿��� heap�������� Simple�̶�� ������ �޸𸮸� �Ҵ��ϰ�, SimpleŸ�� sp2 ������ ������ stack�� ����� heap�� �޸� �ּҸ� ���� 

	cout << endl << "end of main" << endl;
	delete sp1; // delete �����ڸ� �̿��� sp1�� ���� �޸� ������ ����(��ü ��ȯ)
	free(sp2); // delete �����ڸ� �̿��� sp2�� ���� �޸� ������ ����(��ü ��ȯ)
	return 0;
}
