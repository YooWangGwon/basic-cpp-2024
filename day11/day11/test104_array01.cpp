// file : test104_array01.cpp
// date : 240306
// desc : �迭�� ǥ����

#include <iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };		// int�� �迭 ����
	int* parr = arr;					// �迭�� �̸��� �ּ��̴�.

	printf("arr �ּ�: %p\n", arr);
	printf("arr ũ��: %d\n", sizeof(arr));	// int ũ�� 4 byte X �� ����(5) = 20 byte
	
	// ���� �� ������ �ּҰ��� ���� -> ����� �� ���� �ٸ� �޸� ������ �Ҵ� �ޱ� ����
	printf("arr[0] �ּ�: %p\n", &arr[0]);	// arr[0]�� �տ� �ּ� �����ڸ� �ٿ� arr 0������ �ּҸ� ���
	printf("arr[1] �ּ�: %p\n", &arr[1]);	// arr[1]�� �տ� �ּ� �����ڸ� �ٿ� arr 1������ �ּҸ� ���
	printf("arr + 1:%p\n", arr + 1);		// arr + 1�� �ּҰ��� arr[1]�� �ּҰ��� ���� -> ���� ��, ���� �ǹ�

	printf("parr �ּ�: %p\n", &parr);	// ����Ʈ ���� parr�� �ּ�
	printf("parr ������ : %p\n", parr);	// parr�� ����Ű�� �迭 arr�� �ּҸ� ����
	printf("parr+1 : %p\n", parr + 1);	// �迭 arr�� 1������ �ּҿ� ����
	printf("parr[0]:%d\t *pa: %d\t arr[0]: %d\n", parr[0], *parr, arr[0]);


	return 0;
}