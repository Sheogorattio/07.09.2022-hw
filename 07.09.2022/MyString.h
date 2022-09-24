#pragma once
#include<iostream>
#include <initializer_list>
using namespace std;
class MyString {
private:
	char* str;
	int length;
	static int counter;
	friend ostream& operator<<(ostream& os, const MyString& a);
public:

	MyString();
	MyString(initializer_list<char> a);
	MyString(const MyString& obj);
	MyString(int size);
	MyString(const char* s);
	MyString(MyString&& obj);
	~MyString();
	void Input();
	void MyStrCpy(const MyString& obj);
	bool MyStrStr(const char* s)const;
	int MyChr(char c)const;
	int MyStrLen();
	void MyStrCat(MyString& obj);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b)const;
	void Print() const;
	static int GetCount();
	static void DemCount();
	MyString& operator= (const MyString& obj);
	MyString& operator= ( MyString&& obj);
	void operator() ();
	char operator[] (int i);
	operator int();
	operator char* ();
	
};

void PrintNum(int a);
void PrintStr(const char* a);