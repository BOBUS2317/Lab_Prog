#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool is_num_good(const string& str) {
	int size = 0;
	if (isdigit(str[0])) {
		size++;
	}
	else if (str[0] != '+') {
		return false;
	}

	for (int i = 1; i < str.size(); i++) {
		if (isdigit(str[i])) {
			size++;
		}
		else if (string(" -()").find(str[i]) == string::npos) {
			return false;
		}
	}
	if (size == 10 || size == 11) {
		return true;
	}
	return false;
}

string get_only_nums(const string& str) {
	string new_str = "";
	for (char el : str) {
		if (isdigit(el)) {
			new_str += el;
		}
	}
	return new_str;
}

string unify_num(const string& num) {
	if (num.size() == 11) {
		return string{ '+', num[0], ' ', '(', num[1], num[2], num[3], ')', ' ', num[4], num[5], num[6], '-', num[7], num[8], '-', num[9], num[10] };
	}
	else {
		return "+7 " + string{ '(', num[0], num[1], num[2], ')', ' ', num[3], num[4], num[5], '-', num[6], num[7], '-', num[8], num[9] };
	}
}


int main(int, char**) {
	vector<string> vec = { "+7 (999) 123-45-67",
	"8-999-123-45-67",
	"+1 212 456-7890",
	"999-123-45-67",
	"+7999123456789",
	"123456789"
	};
	unsigned int good_nums = 0;
	for (string str : vec) {
		if (is_num_good(str)) {
			cout << unify_num(get_only_nums(str)) << endl;
			good_nums++;
		}
	}
	cout << "Total numbers: " << vec.size() << endl;
	cout << "Good numbers: " << good_nums << endl;
	cout << "Bad numbers: " << vec.size() - good_nums << endl;
}