# include <iostream>
# include <cstring>
using namespace std;

template<typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>		// 대표 자료형을 입력하지 않고 밑에 특정 자료형을 기입
char* Max(char* a, char* b)						// 문자열의 길이 비교 : char* 형에 대해서 특수화
{
	cout << "char*Max<char*>(cahr*a, char*b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>	
const char* Max(const char* a, const char* b)	// 사전 편찬 순서 비교 : const char* 형에 대해서 특수화
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