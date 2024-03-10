#include "Training.h"
#include "TrainingFunc.cpp"
#include <string>
#include <typeinfo>
using namespace std;

int main(void)
{
	Product* product[100] = {};
	int click1 = 0;
	int i = 0;	// 생성된 객체 포인터의 개수
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
		if (cin.fail())
		{
			cin.ignore(INT_MAX, '\n');	// 입력하여 문자로 인식한'\n'도 무시
			cin.clear();				// 입력 가능한 상태로 되돌리기
		
		rewind(stdin);					// 입력 버퍼 비우기

		cout << "1~4중에 입력하세요. > " << endl;
		}	
		else if (click1 == 1)
		{
			cout << "_____[상품 추가]_____" << endl;
			cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;
			int click2 = 0;
		tryAgain1:
			cin >> click2;
			if (cin.fail())
			{
				cin.ignore(INT_MAX, '\n'); // 입력하여 문자로 인식한'\n'도 무시
				cin.clear();

				rewind(stdin);

				cout << "1~4중에 입력하세요. > ";
				goto tryAgain1;
			}
			else if (click2 == 1)	// 상품추가 - 책
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
				cout << "1~4중에 입력하세요." << endl;
			}
		}
		else if (click1 == 2) // 상품 출력
		{
			int click3 = 0;
			cout << "_____[상품 출력]_____" << endl;
			cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;
		tryAgain2:
			cin >> click3;
			if (cin.fail())
			{
				cin.ignore(INT_MAX, '\n'); // 입력하여 문자로 인식한'\n'도 무시
				cin.clear();

				rewind(stdin);

				cout << "1~4중에 입력하세요. > ";
				goto tryAgain2;
			}

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
				cout << "1~4중에 입력하세요." << endl;
				continue;
			}
		}
		else if (click1 == 3)	// 상품 검색
		{
			int click4 = 0;
			string searchThing;
			cout << "_____[상품 검색]_____" << endl;
			cout << "검색하고 싶은 상품의 종류를 선택하세요." << endl;
			cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;
		tryAgain3:
			cin >> click4;
			if (cin.fail())
			{
				cin.ignore(INT_MAX, '\n'); // 입력하여 문자로 인식한'\n'도 무시
				cin.clear();

				rewind(stdin);

				cout << "1~4중에 입력하세요. > ";
				goto tryAgain3;
			}
			if (click4 == 1)	// 상품 검색 -> 책
			{
				int Searchresult = 0;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Book")
					{
						product[n]->ShowProduct();
					}
				}
				cout << "검색하고 싶은 도서명을 입력하세요. > ";
				cin >> searchThing;
				cout << "[검색 결과]" << endl;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->getInfo().find(searchThing) != string::npos)
					{
						product[n]->ShowProduct();
						Searchresult += 1;
					}
				}
				if (Searchresult == 0)
				{
					cout << "검색한 상품이 없습니다." << endl;
				}
			}
			else if (click4 == 2)	// 상품 검색 -> 핸드폰
			{
				int Searchresult = 0;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Handphone")
					{
						product[n]->ShowProduct();
					}
				}
				cout << "검색하고 싶은 휴대폰 모델명을 입력하세요. > ";
				cin >> searchThing;
				cout << "[검색 결과]" << endl;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->getInfo().find(searchThing) != string::npos)
					{
						product[n]->ShowProduct();
						Searchresult += 1;
					}
				}
				if (Searchresult == 0)
				{
					cout << "검색한 상품이 없습니다." << endl;
				}
			}
			else if (click4 == 3)	// 상품 검색 -> 컴퓨터
			{
				int Searchresult = 0;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->mytype() == "Computer")
					{
						product[n]->ShowProduct();
					}
				}
				cout << "검색하고 싶은 컴퓨터 모델명을 입력하세요. > ";
				cin >> searchThing;
				cout << "[검색 결과]" << endl;
				for (int n = 0; n < i; n++)
				{
					if (product[n]->getInfo().find(searchThing) != string::npos)
					{
						product[n]->ShowProduct();
						Searchresult += 1;
					}
				}
				if (Searchresult == 0)
				{
					cout << "검색한 상품이 없습니다." << endl;
				}
			}
			else if (click4 == 4)	// 상품 검색 -> 뒤로가기
			{
				continue;
			}
			else
			{
				cout << "1~4중에 입력하세요." << endl;
				continue;
			}
		}
		else if (click1 == 4)
		{
			break;
		}
		else
		{
			cout << "1~4중에 입력하세요." << endl;
			continue;
		}
	}

	delete []product;	// 메모리 반환
	return 0;
}