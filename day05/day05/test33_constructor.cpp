// file : test33_constructor
// date : 240226
// desc : ������

# include <iostream>
using namespace std;

class MyClass {
	int num;

public:
	MyClass() {
		cout << "������ ȣ��: MyClass()" << endl;
		num = 10;
	}
	MyClass(int anum)
	{
		cout << "������ ȣ��: MyClass(int )" << endl;
		num = anum;
	}
	void MyClassInfo()
	{
		cout << "num: " << num << endl;
	}
};

int main()
{
	//MyClass * m = new MyClass(); // heap�������� �޸𸮸� �Ҵ�޾� ����
	// MyClass m1(); ->m1�̶�� �Լ��� ȣ���ϴ� ���°� ��
	MyClass m2; // -> ��ü���� ��ɾ��� �����ڴ� �ڵ� ȣ�� ��
	m2.MyClassInfo();
	MyClass m3(20); // ���ڰ� �޶����� MyClass(int anum) �����ڰ� ȣ���
	m3.MyClassInfo();
	return 0;
}