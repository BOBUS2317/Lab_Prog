#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words(50, "AppleOrange");
    words[5] = "Aviation";
    words[10] = "ExtremelyLongWord";

    int countA = count_if(words.begin(), words.end(), [](string s) {
        return !s.empty() && s[0] == 'A';
    });

    for (auto& w : words) {
        transform(w.begin(), w.end(), w.begin(), [](char c) {
            return string("aeiouAEIOU").find(c) != string::npos ? '*' : c;
        });
    }

    auto longest = max_element(words.begin(), words.end(), [](string a, string b) { 
        return a.size() < b.size(); 
    });

    vector<string> filtered;
    copy_if(words.begin(), words.end(), back_inserter(filtered), [](string s) { 
        return s.size() > 7; 
    });

    cout << "Words starting with 'A': " << countA << endl;
    if (longest != words.end()) cout << "Longest word size: " << longest->size() << endl;
    cout << "Filtered words (>7 chars): " << filtered.size() << endl;

    return 0;
}