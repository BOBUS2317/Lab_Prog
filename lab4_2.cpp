#include <iostream>
using namespace std;
void replAll(string& str, const string& old_str, const string& new_str) {
	while (str.find(old_str) != string::npos) {
		str.replace(str.find(old_str), old_str.size(), new_str);
	}
}

int main(int, char**) {
	setlocale(LC_ALL, "Russian");
	string str = "The quick brown fox jumps over the lazy dog";
	cout << str << endl;
	cout << "fox находится по индексу " << str.find("fox") << endl;

	cout << "Есть ли cat в строке? ";
	if (str.find("cat") == string::npos) {
		cout << "Нет" << endl;
	}
	else {
		cout << "Да" << endl;
	}
	str.replace(str.find("quick"), 5, "slow");
	cout << str << endl;
	replAll(str, "o", "0");
	cout << str << endl;

	string sub_str = str.substr(3, 4);
	cout << "Подстрока: " << sub_str << endl;
}