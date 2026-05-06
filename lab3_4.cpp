#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

template <typename Func>
long long measure(Func func) {
    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

int main() {
    const int N = 50;
    const string val = "AppleOrange";

    array<string, N> arr; arr.fill(val);
    vector<string> vec(N, val);
    list<string> lst(N, val);

    auto isA = [](const string& s) { return !s.empty() && s[0] == 'A'; };
    auto isVowel = [](char c) { return string("aeiouAEIOU").find(c) != string::npos; };
    auto isLong = [](const string& s) { return s.size() > 7; };
    auto comp = [](const string& a, const string& b) { return a.size() < b.size(); };
    
    auto tr = [&](string& s) { 
        transform(s.begin(), s.end(), s.begin(), [&](char c){ return isVowel(c) ? '*' : c; }); 
    };

    cout << "Words starting with 'A': " << count_if(vec.begin(), vec.end(), isA) << endl;
    auto longest = max_element(vec.begin(), vec.end(), comp);
    cout << "Longest word size: " << (longest != vec.end() ? longest->size() : 0) << endl;
    vector<string> filtered;
    copy_if(vec.begin(), vec.end(), back_inserter(filtered), isLong);
    cout << "Filtered words (>7 chars): " << filtered.size() << endl;

    cout << "\nPerformance Comparison (nanoseconds):" << endl;
    cout << left << setw(20) << "Operation" << "| Array    | Vector   | List" << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << left << setw(20) << "1. find_if (A)" << "| " 
         << setw(8) << measure([&](){ find_if(arr.begin(), arr.end(), isA); }) << " | "
         << setw(8) << measure([&](){ find_if(vec.begin(), vec.end(), isA); }) << " | "
         << setw(8) << measure([&](){ find_if(lst.begin(), lst.end(), isA); }) << endl;

    cout << left << setw(20) << "2. transform (*)" << "| "
         << setw(8) << measure([&](){ for(auto& s : arr) tr(s); }) << " | "
         << setw(8) << measure([&](){ for(auto& s : vec) tr(s); }) << " | "
         << setw(8) << measure([&](){ for(auto& s : lst) tr(s); }) << endl;

    cout << left << setw(20) << "3. max_element" << "| "
         << setw(8) << measure([&](){ max_element(arr.begin(), arr.end(), comp); }) << " | "
         << setw(8) << measure([&](){ max_element(vec.begin(), vec.end(), comp); }) << " | "
         << setw(8) << measure([&](){ max_element(lst.begin(), lst.end(), comp); }) << endl;

    vector<string> f1, f2, f3;
    cout << left << setw(20) << "4. copy_if (>7)" << "| "
         << setw(8) << measure([&](){ copy_if(arr.begin(), arr.end(), back_inserter(f1), isLong); }) << " | "
         << setw(8) << measure([&](){ copy_if(vec.begin(), vec.end(), back_inserter(f2), isLong); }) << " | "
         << setw(8) << measure([&](){ copy_if(lst.begin(), lst.end(), back_inserter(f3), isLong); }) << endl;

    cout << "\nPerformance Analysis:" << endl;
    cout << "- Array/Vector: Show better performance due to contiguous memory allocation (CPU cache friendly)." << endl;
    cout << "- List: Slower because of non-contiguous memory and pointer overhead for each element." << endl;

    return 0;
}