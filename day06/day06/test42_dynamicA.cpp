// file : test42_dynamicA.cpp
// date : 240227
// desc : �޸� ���� �Ҵ�(new ������ ���)

// ���� �Ҵ� : ���� �߿� �޸𸮸� �Ҵ�޴´�.

#include <iostream>
using namespace std;

int main()
{
	cout << "int ũ�� : " << sizeof(int) << endl;
	int *pi = new int;	// heap ������ intũ��(4byte)��ŭ �޸𸮰����� �Ҵ�ް� �Ҵ���� �ּҸ� intŸ������ Return 
					    // �ּҰ��̱� ������ �Ϲ� ������ �ƴ� ������ ����(* pi)�� ���

	*pi = 10;	// *pi:�����Ͱ� ����Ű�� ���� ��������� �ǹ� -> ��������� 10�� ����־��
	cout << "pi�� ����Ű�� ���� ����� ��: " << *pi << endl;

	delete pi;	// heap ������ ���� �Ҵ���� �޸� ������ ��ȯ(�ݵ�� ��ȯ!!), JAVA������ garbage collector�� �ڵ����� ��ȯ����.

	int *pary = new int[10];	  // �迭 ���·� �Ҵ�
	cout << sizeof(pary) << endl; // ����Ʈ ���� ��ü�� ũ��� 8byte 
	for (int i = 0; i < 10; i++)
	{
		pary[i] = i + 10;	// �迭�� �� �濡 ����(���)���� ����ִ´�. ex) pary[0]=10
	}

	for (int i = 0; i < 10; i++)
	{
		printf("pary[%d] : %d\n", i, pary[i]);
	}

	delete[] pary; // �迭�� �����Ҵ���� �޸�̸� �迭�� ��ȯ

	// new �����ڷ� �迭�� ����� ��� �����ڸ� ȣ��
	// int arr[10]ó�� �迭�� ����� ��� �����ڸ� ȣ���ϴ� ���� �ƴ�


	return 0;
}