// file : test100_AssignShallowCopyError.cpp
// date :240306
// desc : ����Ʈ ���� �������� ������

# include <iostream>
# include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person& operator=(const Person& ref)    // ���� ���縦 ���� = ������ �����ε�
    {
        delete[]name; ;                 // �����ϱ� ���� �޸��� ������ ���� ���� ������ ����Ű�� �޸� ���� ��ȯ
        int len = strlen(ref.name) + 1; 
        name = new char[len];           // heap�������� '���� ����� ���ڿ� ũ��+1'��ŭ�� �޸� ���� �Ҵ� ����
        strcpy(name, ref.name);         // ���� ����� ���ڿ��� �����Ͽ� name �޸� ������ ����
        age = ref.age;
        return *this;                   // ����� ����� Person��ü �ڽ��ڽ��� return
    }
    void ShowPersonInfo() const
    {
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
    }
    ~Person()
    {
        delete[]name;   // �Ҹ��ϸ鼭 name�� �Ҵ�� heap ������ �޸� ������ ��ȯ
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2 = man1;    // man1�� ���� man2�� ����� ��� ���Ե�. ����Ʈ ���� �������� ���, man1�� man2�� ������ �ּҰ��� �����Ե� -> ������ �޸� ������ ����Ű�� ��
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;       // man1�� �Ҹ�Ǹ鼭 man1�� ����Ű��
}                   // heap������ �޸� ���� ��ȯ. ����Ʈ ���Կ����ڸ� �� ���, man2�� ����ִ� ������ ����Ű�� ������ �߻�
