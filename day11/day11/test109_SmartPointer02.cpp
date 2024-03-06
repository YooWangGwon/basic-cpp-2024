# include <iostream>
// using namespace std;

class MyClass
{
private:
	int* ptr;
public:
	MyClass(int p) : ptr(new int[100]) // int Ÿ���� �� 100���� �޸� ������ �Ҵ����
	{	
		printf("������ ȣ��\n");
	}
	~MyClass()
	{
		printf("�Ҹ��� ȣ��\n");
		delete[] ptr;
	}
};

int main(void)
{
	MyClass *m1 = new MyClass(10); // new �����ڸ� ���� heap ������ MyClass Ÿ�� ��ü ���� -> �Ҹ��� �ȵ�!
	std::cout << "==================================" << std::endl;
	std::unique_ptr<MyClass>m2(new MyClass(20));

	return 0;
}