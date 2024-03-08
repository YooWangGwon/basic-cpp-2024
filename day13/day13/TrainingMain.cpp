#include "Training.h"
#include "TrainingFunc.cpp"
#include <string>
#include <typeinfo>
using namespace std;

int main(void)
{
	Product* product[100] = {};
	int click1 = 0;
	int i = 0;
	string id;
	int price = 0;
	string producer;
	string ISBN;
	string author;
	string title;
	string model;
	int RAM = 0;
	string cpu;

	while (true)
	{
		cout << "-----상품 관리 프로그램-----" << endl;
		cout << "1. 상품추가 2. 상품출력 3. 상품검색 4. 종료" << endl;
		cin >> click1;
		if (click1 == 1)
		{
			cout << "_____[상품 추가]_____" << endl;
			cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;
			int click2 = 0;
			cin >> click2;
			if (click2 == 1)	// 상품추가 - 책
			{
				cout << "ID > ";
				cin >> id;
				cout << "가격 > ";
				cin >> price;
				cout << "출판사 > ";
				cin >> producer;
				cout << "ISBN > ";
				cin >> ISBN;
				cout << "저자 > ";
				cin >> author;
				cout << "도서명 > ";
				cin >> title;
				product[i] = new Book(id, price, producer, ISBN, author, title);
				i++;
				continue;
			}
			else if (click2 == 2)	// 상품추가 - 핸드폰
			{
				cout << "ID > ";
				cin >> id;
				cout << "가격 > ";
				cin >> price;
				cout << "제조사 > ";
				cin >> producer;
				cout << "모델명 > ";
				cin >> model;
				cout << "RAM 크기 > ";
				cin >> RAM;
				product[i] = new Handphone(id, price, producer, model, RAM);
				i++;
				continue;
			}
			else if (click2 == 3)	// 상품추가 - 컴퓨터
			{
				cout << "ID > ";
				cin >> id;
				cout << "가격 > ";
				cin >> price;
				cout << "제조사 > ";
				cin >> producer;
				cout << "모델명 > ";
				cin >> model;
				cout << "CPU > ";
				cin >> cpu;
				cout << "RAM 크기 > ";
				cin >> title;
				product[i] = new Computer(id, price, producer, model, cpu, RAM);
				i++;
				continue;
			}
			else if (click2 == 4)	// 상품추가 - 뒤로가기
			{
				continue;
			}
			else
			{
				cout << "숫자를 다시 입력하세요" << endl;
			}
		}
		else if (click1 == 2) // 상품 출력
		{
			int click3 = 0;
			cout << "_____[상품 출력]_____" << endl;
			cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;
			cin >> click3;

			if (click3 == 1)	// 상품 출력 -> 책
			{
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Book")
					{
						product[n]->ShowProduct();
					}

				}
			}
			else if (click3 == 2)	// 상품 출력 -> 휴대폰
			{
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Handphone")
					{
						product[n]->ShowProduct();
					}
				}
			}
			else if (click3 == 3)	// 상품 출력 -> 컴퓨터
			{
				for (int n = 0; n < i; n++)
				{
					if (typeid(product[n]).name() == "Computer")
					{
						product[n]->ShowProduct();
					}
				}
			}
			else if (click3 == 4)	// 상품 출력 -> 뒤로 가기
			{
				continue;
			}
			else
			{
				cout << "숫자를 다시 입력하세요" << endl;
				continue;
			}
		}
		else if (click1 == 3)
		{
			int click4 = 0;
			string titlename;
			cout << "_____[상품 검색]_____" << endl;
			cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;
			cin >> click4;
			if (click4 == 1)
			{
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Book")
					{
						product[n]->ShowProduct();
					}
				}
				cout << "검색하고 싶은 도서명을 입력하세요. > ";
				cin >> titlename;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->getInfo() == titlename)
					{
						product[n]->ShowProduct();
					}
				}
			}
			else if (click4 == 2)
			{
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Handphone")
					{
						product[n]->ShowProduct();
					}
				}
				cout << "검색하고 싶은 휴대폰 모델명을 입력하세요. > ";
				cin >> titlename;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->getInfo() == titlename)
					{
						product[n]->ShowProduct();
					}
				}
			}
			else if (click4 == 3)
			{
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Computer")
					{
						product[n]->ShowProduct();
					}
				}
				cout << "검색하고 싶은 컴퓨터 모델명을 입력하세요. > ";
				cin >> titlename;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->getInfo() == titlename)
					{
						product[n]->ShowProduct();
					}
				}
			}
			else if (click4 == 4)
			{
				continue;
			}
			else
			{
				cout << "숫자를 다시 입력하세요" << endl;
				continue;
			}
		}
		else if (click1 == 4)
		{
			break;
		}
		else
		{
			cout << "잘못된 입력 번호입니다." << endl;
			continue;
		}
	}

	return 0;
}