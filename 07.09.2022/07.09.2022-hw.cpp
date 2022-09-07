#include <iostream>
using namespace std;

class MyString {
private:
	char* str;
	int length;
public:
	MyString();
	MyString(int size);
	MyString(const char* s);
	~MyString();
	void InputOut();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& obj);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
};

MyString::MyString() {
	length = 80;
	str = new char[length+1];
	str[length+1] = '\0';
	
}
MyString::MyString(int size) {
	length = size;
	str = new char[size + 1];
	str[size + 1] = '\0';
}
MyString::MyString(const char* s) {
	int size = strlen(s);
	str = new char[size + 1];
	str[size + 1] = '\0';
}
MyString::~MyString() {
	delete[] str;
}
