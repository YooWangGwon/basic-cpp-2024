// file : test27_fileDiv.h
// date : 240223
// desc : Ŭ���� ���� �ǽ�


#pragma once //#ifndef __CAR_H__
			//#define __CAR_H__ �۾��� ���� �ʾƵ� ��


/*
test25_fileDiv.h ������� : ����
*/
/*
class AClass {
private: 
	int num;

public: // ���� ����������:��𼭵��� ���� ����
	AClass(int anum);
	void Alnfo();
};
*/
class Human {
private:
	char name[30];
	const int age;
	char job[20];
	const int birth;
public:
	Human(const char* Hname, int Hage, const char* Hjob, const int Hbirth);
	void humanInfo();
};