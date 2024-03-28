#ifndef __PRODUCT_
#define __PRODUCT_
#include <string>
using namespace std;

class Product
{
private:
	string id;
	int price;
	string producer;
public:
	Product();
	Product(string Pid, int Pprice, string Pproducer);
	virtual void ShowProduct();
	virtual string mytype();
	virtual string getInfo();
	~Product();
};

class Book : public Product
{
private:
	string ISBN;
	string author;
	string title;
public:
	Book(string Bid, int Bprice, string Bproducer, string BISBN, string Bauthor, string Btitle);
	void ShowProduct();
	string mytype();
	string getInfo();
};

class Handphone : public Product
{
private:
	string model;
	int RAM;
public:
	Handphone(string Hid, int Hprice, string Hproducer, string Hmodel, int HRAM);
	void ShowProduct();
	string mytype();
	string getInfo();
};

class Computer : public Product
{
private:
	string model;
	string cpu;
	int RAM;
public:
	Computer(string Cid, int Cprice, string Cproducer, string Cmodel, string Ccpu, int CRAM);
	void ShowProduct();
	string mytype();
	string getInfo();
};

#endif