#include "test127_1_Product.h"
#include <iostream>
#include <string>

using namespace std;

Product::Product()
{ 
	price = 0;
}

Product::Product(string Pid, int Pprice, string Pproducer)
{
	id = Pid;
	price = Pprice;
	producer = Pproducer;
}

void Product::ShowProduct()
{
	cout << "ID : " << id << endl << "가격 : " << price << " 원" << endl << "제조사(출판사) : " << producer << endl;
}

string Product::mytype()
{
	return "Product";
}

string Product::getInfo()
{
	return "ID";
}

Product::~Product()
{
	cout << "Product 소멸자 실행" << endl;
}

Book::Book(string Bid, int Bprice, string Bproducer, string BISBN, string Bauthor, string Btitle) : Product(Bid, Bprice, Bproducer)
{
	ISBN = BISBN;
	author = Bauthor;
	title = Btitle;
}

void Book::ShowProduct()
{
	cout << "[Book]" << endl;
	Product::ShowProduct();
	cout << "ISBN : " << ISBN << endl << "저자 : " << author << endl << "도서명 : " << title << endl;
	cout << "---------------" << endl;
}

string Book::mytype()
{
	return "Book";
}

string Book::getInfo()
{
	return title;
}

Handphone::Handphone(string Hid, int Hprice, string Hproducer, string Hmodel, int HRAM) : Product(Hid, Hprice, Hproducer)
{
	model = Hmodel;
	RAM = HRAM;
}

void Handphone::ShowProduct()
{
	cout << "[Handphone]" << endl;
	Product::ShowProduct();
	cout << "모델명 : " << model << endl << "RAM 크기 : " << RAM << " G" << endl;
	cout << "---------------" << endl;
}

string Handphone::mytype()
{
	return "Handphone";
}

string Handphone::getInfo()
{
	return model;
}

Computer::Computer(string Cid, int Cprice, string Cproducer, string Cmodel, string Ccpu, int CRAM) : Product(Cid, Cprice, Cproducer)
{
	model = Cmodel;
	cpu = Ccpu;
	RAM = CRAM;
}

void Computer::ShowProduct()
{
	cout << "[Computer]" << endl;
	Product::ShowProduct();
	cout << "모델명 : " << model << endl << "CPU : " << cpu << endl << "RAM 크기 : " << RAM << " G" << endl;
	cout << "---------------" << endl;
}


string Computer::mytype()
{
	return "Computer";
}

string Computer::getInfo()
{
	return model;
}