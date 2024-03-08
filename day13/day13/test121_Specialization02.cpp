# include <iostream>
# include <cstring>
using namespace std;

template<typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>		// ��ǥ �ڷ����� �Է����� �ʰ� �ؿ� Ư�� �ڷ����� ����
char* Max(char* a, char* b)						// ���ڿ��� ���� �� : char* ���� ���ؼ� Ư��ȭ
{
	cout << "char*Max<char*>(cahr*a, char*b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>	
const char* Max(const char* a, const char* b)	// ���� ���� ���� �� : const char* ���� ���ؼ� Ư��ȭ
{
	cout << "const char*Max(const char*a, const char*b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;	// const char*

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;		// char*
	return 0;
}