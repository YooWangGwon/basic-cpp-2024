// file : test18_StdCPPFunc.cpp
// date : 240223
// desc : C++���� C����� ǥ�� �Լ� ȣ���ϱ�(p.96~99)

// C�� �ִ� ��������� ���������� ���� ����� c�� ���̰� Ȯ���ڴ� ����


# include <cmath> // math.h
# include <cstdio> // stdio.h
# include <cstring> // string.h
using namespace std;

int main(void)
{
	char str1[] = "Result";
	char str2[30];

	strcpy(str2, str1);
	printf("%s: %f \n", str1, sin(0.14));
	printf("%s: %f \n", str2, abs(-1.25));
}
