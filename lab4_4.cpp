#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

unsigned int findAll(const string& str, const string& sub) {
	unsigned int count = 0;
	int i = str.find(sub);
	while (i != string :: npos) {
		count++;
		i = str.find(sub, i + 1);
	}
	return count;
}

void replAll(string& str, const string& old_str, const string& new_str) {
	while (str.find(old_str) != string::npos) {
		str.replace(str.find(old_str), old_str.size(), new_str);
	}
}

int main(int, char**) {
	setlocale(LC_ALL, "Russian");
	string str = "Programming is fun. C++ is powerful. Programming requires practice.";
	unsigned int symbol_counter = 0;
	unsigned int word_counter = 0;
	unsigned int sentence_counter = 0;
	unsigned int is_counter = 0;
	for (char c : str) {
		if (c != ' ') {
			symbol_counter++;
		}
		else {
			word_counter++;
		}
		if (c == '.') {
			sentence_counter++;
		}
	}

	cout << "Всего символов: " << symbol_counter << endl;
	cout << "Всего слов: " << word_counter + 1 << endl;
	cout << "Всего предложений: " << sentence_counter << endl;

	cout << "Всего is: " << (findAll(str, " is ") + findAll(str, " is.")) << endl;

	for (char el : ".,!?:;") {
		is_counter += findAll(str, (string(" is") + el));
	}
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (int i = 0; i < 20; i++) {
		cout << str[i];
	}
	cout << endl;
	string new_str = str;
	replAll(new_str, ".", "!");
	cout << new_str;
}