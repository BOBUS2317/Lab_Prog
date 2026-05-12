#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> split(const string& str, char sep) {
	vector<string> str_vec;
	int i=-1, next_i = str.find(sep);
	if (next_i == string::npos) {
		str_vec.push_back(str);
	}
	else {
		do {
			str_vec.push_back(str.substr(i + 1, next_i - i - 1));
			i = next_i;
			next_i = str.find(sep, i + 1);
		} while (
			(i != string::npos)
			);
	}
	return str_vec;
}

string join(vector<string>::iterator st, vector<string>::iterator end, string sep) {
	string result = "";
	for (auto it = st; it != end; it++) {
		result += *it + sep;
	}
	if (result != "") result.erase(result.size() - sep.size());
	return result;
}

void getAnswer(const string& str) {
	vector<string> vec = split(str, ',');
	cout << "Число элементов: " << vec.size() << endl;
	cout << "Элементы:" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << (i + 1) << ") " << vec[i] << endl;
	}
	auto x = max_element(vec.begin(), vec.end(), [](string a, string b) {return a.size() < b.size(); });
	cout << "Самое длинное слово: " << *x << endl;

	cout << join(vec.begin(), vec.end(), " | ");
}
int main(int, char**) {
	setlocale(LC_ALL, "Russian");
	getAnswer(",бип бип,рооблокс,тетрагидропиранилциклопентилтетрагидропиридопиридиновые,добрый кола");
}