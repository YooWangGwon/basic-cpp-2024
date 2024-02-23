// file : test25_fileDiv.h
// date : 240223
// desc : 클래스 선언


#pragma once //#ifndef __CAR_H__
			//#define __CAR_H__ 작업을 하지 않아도 됨


/*
test25_fileDiv.h 헤더파일 : 선언
*/
/*
class AClass {
private: 
	int num;

public: // 접근 제어지시자:어디서든지 접근 가능
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
