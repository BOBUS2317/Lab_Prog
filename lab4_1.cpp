#include <iostream>
#include <cstring>
using namespace std;


int main(int, char**) {
	setlocale(LC_ALL, "Russian");
	const char* chr = "Я самый крутой, наверное";
	string str = "Я самый крутой, наверное";
	string str2 = " очень старался)";
	cout << chr << endl;
	cout << str << endl;

	cout << "Длина char - " << strlen(chr) << endl;
	cout << "Длина string - " << str.size() << endl;

	cout << str + str2 << endl;
	(chr == str) ? cout << "char и str равны" : cout << "char и str не равны";
}