#include <iostream>
using namespace std;

class MyString {
private:
	char* str;
	int length;
	static int counter;
public:
	
	MyString();
	MyString(const MyString& obj);
	MyString(int size);
	MyString(const char* s);
	~MyString();
	void InputOut();
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
};
int MyString::counter = 0;

int MyString::GetCount() {
	return counter;
}
void MyString::DemCount() {
	counter--;
}
MyString::MyString() {
	length = 80;
	str = new char[length+1];
	*(str+length) = '\0';
	counter++;
}
MyString::MyString(const MyString& obj){
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = obj.length;
	counter++;
}
MyString::MyString(int size) {
	length = size;
	str = new char[size + 1];
	*(str+size) = '\0';
	counter++;
}
MyString::MyString(const char* s) {
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
	counter++;
}
MyString::~MyString() {
	delete[] str;
	counter--;
}
int MyString::MyStrLen() {//вывод длинны строки
	length = 0;
	for (int i = 0;; i++) {
		length = i;
		if (*(str + i) == '\0') {
			break;
		}
	}
	return length;
}
void MyString::MyStrCpy( const MyString& obj){//копирование строки
	if (str != nullptr) {
		delete[]str;
	}
	str = new char[strlen(obj.str) + 1];
	length = obj.length;
	char ch;
	for (int i=0;; i++) {
		ch = *(obj.str+i);
		*(str + i) = ch;
		if (ch == '\0') {
			break;
		}
	}
}
void MyString::Print() const {//это моё
	cout << str<< endl;
}
void MyString::InputOut() {//ввод и вывод
	int const buff_size = 255;
	char buffer[buff_size];
	cout << "enter text\n";
	cin.getline(buffer, buff_size - 1);
	if (str != nullptr) {
		delete[] str;
	}
	str = new char[strlen(buffer) + 1];
	strcpy_s(str, strlen(buffer) + 1, buffer);
	length = strlen(str);
	cout << str << "\n";
}
int MyString::MyStrCmp(MyString& b)const {//сравнение строк по длинне
	unsigned long long size_a = strlen(str);
	unsigned long long size_b = strlen(b.str);
	if (size_a == size_b) { return 0; }
	return (size_a > size_b) ? 1 : -1;
}
void MyString::MyStrCat(MyString& b) {//конкатенация строк
	unsigned long long size_a = strlen(str);
	unsigned long long size_b = strlen(b.str);
	int buff_size = strlen(str) + strlen(b.str) + 1;
	char* buff = new char[buff_size];
	
	int count = 0;
	while (*(str + count) != '\0') {
		*(buff+count) = *(str+count);
		count++;
	}
	int count2 = 0;
	while (*(b.str + count2) != '\0') {
		*(buff+count) = *(b.str+count2);
		count++;
		count2++;
	}
	*(buff + count) = '\0';

	delete[] str;
	str = new char[size_a + size_b + 1];
	strcpy_s(str, size_a + size_b +1, buff);
	length = strlen(str);
	delete[]buff;
}
int MyString::MyChr(char c)const {//поиск указанного символа
	int counter = 0;
	for (int i = 0;; i++) {
		if (*(str + counter) == c || *(str + counter)== '\0') {
			break;
		}
		counter++;
	}
	if (counter == length) counter = -1;//если нет такой буквы
	return counter;
}
void MyString::MyDelChr(char c) {//удаление указанного символа
	if (str == nullptr) {
		return;
	}
	int ch_count = 0;//сколько раз всречается буква в слове
	for (int i = 0;*(str+i) !='\0'; i++) {
		if (*(str + i) == c) {
			ch_count++;
		}
	}
	int count = 0, buff_size = strlen(str)-ch_count, position=0;
	char* buff = new char[buff_size+1];
	for (int i = 0;i<=buff_size+1;i++) {//запись в буфер с пропуском указанной буквы
		if (*(str + i) != c) {
			*(buff + position) = *(str + i);
			position++;
		}
		else {
			continue;
		}
	}
	*(buff + buff_size) = '\0';
	delete[] str;
	str = new char[buff_size + 1];
	strcpy_s(str, buff_size + 1, buff);
	length = buff_size;
	delete[] buff;
}
bool MyString::MyStrStr(const char* s)const {//подстрока в строке
	int s_size = strlen(s);
	int orig_size = length;
	bool check=0;
	for (int i = 0; i <= orig_size - s_size; i++) {
		if (*(str + i) == *(s)) {
			check = 1;
			int position = 0;
			for (int j = i; position < s_size; j++) {
				if (*(str + j) != *(s + position)) {
					check = 0;
					break;
				}
				position++;
			}
		}
	}
	return check;
}

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