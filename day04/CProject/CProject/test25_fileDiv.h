// file : test25_fileDiv.h
// date : 240223
// desc : Ŭ���� ����


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
	char* name[30];
	int age;
	char* job[20];
public:
	Human(const char Hname, int Hage, const char Hjob);
	void humanInfo();
};
