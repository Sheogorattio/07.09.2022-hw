#include<iostream>
#include "MyString.h"

using namespace std;

int main() {
	cout << "obj1\n";
	MyString obj = { 'T', 'E', 'X','T'};
	MyString obj2;
	cout << "obj2\n";
	obj2.Input();
	cout << "obj3\n";
	MyString obj3 = move(obj);
	cout << "obj4\n";
	MyString obj4;
	obj4 = move(obj2);

	cout << "\n--------------------------------------------------------\n\n\n";
	cout << "obj1 \n" << obj << endl << "obj2 \n" << obj2 <<endl << "obj3\n"  << obj3 <<endl << "obj4\n" <<obj4 << endl;
}