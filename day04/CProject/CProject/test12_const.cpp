// file : test12
// date : 20240223
// desc : const

#include <iostream>

int main()
{
	const int num = 10;	 //const:const int����ϸ� int Ÿ���� �ƴ� ������ const int��� Ÿ���� ���ܳ���
	//int& ref = num;	// �׳� int Ÿ������ �� ��� Ÿ�� ����ġ �߻�
	const int& ref =num
	// const Ű���尡 ������ ����� ������ �� �ִ�.(�ӽú����� ���� ����� �����ϰ� �ּҸ� �Ҵ�)
	// ��������(Register) :  �������ʹ� ��ǻ���� �߾� ó�� ��ġ(CPU) ���ο� �ִ� �ſ� ���� �޸� ��ġ
	// ������ �������Ϳ� ������ �Ŀ� ���


}