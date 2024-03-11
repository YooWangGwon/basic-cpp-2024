// file : test129_vector.cpp
// date : 240311
// desc : vector와 vector 멤버함수

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	/*
	vector<int> v; // int타입의 vector v 생성

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
		printf("v[%d]: %d\n", i, v[i]);
		printf("v.size():%ll\n", v.size());			// size : 원소의 개수 리턴
		printf("v.capacity():%d\n", v.capacity());	// 배열 개수가 10개가 되면서 값이 13이 됨 // capacity : 할당되어있는 메모리 공간을 리턴
	}

	v.push_back(20);
	v.push_back(21);

	for (int i = 0; i < v.size(); i++)
	{
		//v.push_back(i + 1);
		printf("v[%d] : %d\n", i, v[i]);
		printf("v.at(i):%d\n", v.at(i));
	}

	cout << "iterator : 반복자" << endl;
	vector<int> ::iterator iter; // vector 안의 iterator 타입의 반복자 iter 생성
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << "iter: " << *iter << endl;
	}
	*/
	vector<string> vs;

	vs.push_back("Hi");
	vs.push_back("Hello");
	vs.push_back("Good Morning");
	cout << "vs.front()" << vs.front() << endl;
	cout << "vs.back()" << vs.back() << endl;
	vector<string>::iterator it;
	for (it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << endl;
	}

	vector<int> v1;		// 크기가 0인 벡터가 생성
	vector<int> v2(5);	// 크기가 5인 벡터가 생성(0으로 초기화됨)
	vector<int> v3 = { 10,20,30 };
	vector<int> v4(10, 7); // 크기가 10이고, 7로 초기화

	return 0;
}