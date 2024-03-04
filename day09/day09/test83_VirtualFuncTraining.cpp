// file : test83_VirtualFuncTraining.cpp
// date : 240304
// desc : 가상함수 연습

#include <iostream>
using namespace std;

class RemoteControl
{
public:
	virtual void on()
	{	}
};

class SamsungTV : public RemoteControl
{
public:
	void on()
	{
		cout << "삼성 TV on" << endl;
}
};

class LGTV : public SamsungTV
{
public:
	void on()
	{
		cout << "LG TV on" << endl;
	}
};

int main(void)
{
	RemoteControl* remote1 = new LGTV();
	RemoteControl* remote2 = new SamsungTV();

	remote1->on();
	remote2->on();
	
	delete remote1; delete remote2; 

	return 0;
}