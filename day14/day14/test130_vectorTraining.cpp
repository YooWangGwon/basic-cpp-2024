// file : test130_vectorTraining.cpp
// date : 2403011
// desc : vector ����

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> v;
	int sum = 0;
	int a = 0;

	while (true)
	{
		cout << "������ �Է��Ͻÿ�(0 ����) > ";
		cin >> a;
		if (!a)		// a���� 0�̸�
		{
			break;	// ����
		}
		v.push_back(a);
		sum += a;
		cout << "��հ� : " << sum / v.size() << endl;
	}

	cout << "���α׷��� �����մϴ�.";

	return 0;
}

