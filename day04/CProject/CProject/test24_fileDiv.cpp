# include <iostream>

class AClass {
private: // �Ӽ��� public���� ���� ����. ������ ��� �ڵ������� private�� �ȴ�.
	int num;

public: // ���� ����������:��𼭵��� ���� ����
	AClass(int anum) { // ������ : �ϳ��� ���� �Է¹޾� �ʵ尪�� �ʱ�ȭ�ϴ� ���� ���
		num = anum;
	}

	void Alnfo() {
		std::cout << "A::num" << num << std::endl;
	}
};

int main()
{
	AClass a(10); // a��� �Լ��� ȣ���ϸ鼭 10�� �Է� -> AClass�� �ִ� ������(num=anum)�� ȣ���
	a.Alnfo();

	return 0;
}