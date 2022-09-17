#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
	/*MyString obj1;
	MyString obj2(45);*/
	MyString obj3("forever");
	MyString obj4(obj3);
	/*cout << obj1.MyStrLen() << endl;
	cout << obj2.MyStrLen() << endl;
	cout << obj3.MyStrLen() << endl;
	obj1.MyStrCpy(obj3);
	obj1.Print();*/
	//obj1.InputOut();
	//obj2.InputOut();
	//cout << obj1.MyStrCmp(obj2) << endl;
	//cout << obj2.MyStrCmp(obj1) << endl;
	//obj1.MyStrCat(obj2);
	//obj1.Print();
	//cout << obj3.MyChr('x');
	//obj3.MyDelChr('x');
	//obj3.Print();
	cout << obj3.MyStrStr("over") << endl << obj3.MyStrStr("ever") << endl << obj3.MyStrStr("for") << endl << obj3.MyStrStr("or")<< endl;
	cout << MyString::GetCount()<< endl;
	obj4.Print();
}