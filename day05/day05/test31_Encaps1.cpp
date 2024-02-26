// file : test31_Encaps1.cpp
// date : 240226
// desc : 캡슐화가 무너진 대표적 사례(p.161~163)

# include <iostream>
using namespace std;

class SinivelCap // 콧물 처치용 캡슐
{
public:
	void Take() const { cout << "콧물이 싹~ 납니다." << endl;} // 변경할 수 있는 가능성을 원천 차단하기 위해 const를 붙임(상수화에 변경될 소지가 있어선 안됨)
};

class SneezeCap //재채기 처치용 캡슐
{
public:
	void Take() const { cout << "재채기가 멋습니다." << endl; }
};

class SnuffleCap // 코막힘 처치용 캡슐
{
public:
	void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap& cap) const { // 변경할 수 있는 가능성을 원천 차단하기 위해 const를 붙임(상수화에 변경될 소지가 있어선 안됨)
		cap.Take(); 
	} 
	void TakeSneezeCap(const SneezeCap& cap) const { 
		cap.Take(); 
	}
	void TakeSnuffleCap(const SnuffleCap& cap) const {
		cap.Take(); 
	}
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}