// file : test18_StdCPPFunc.cpp
// date : 240223
// desc : C++에서 C언어의 표준 함수 호출하기(p.96~99)

// C에 있는 헤더파일을 가져오려면 기존 헤더명에 c를 붙이고 확장자는 생략


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
