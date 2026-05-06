#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int id;
    double gpa;
};

int main() {
    array<Student, 1000> arr;
    vector<Student> vec;
    list<Student> lst;

    for (int i = 0; i < 1000; ++i) {
        Student s = {"Student" + to_string(i), rand() % 10000, (rand() % 40 + 10) / 10.0};
        arr[i] = s;
        vec.push_back(s);
        lst.push_back(s);
    }

    auto print5 = [](const auto& container, const string& title) {
        cout << "--- " << title << " ---" << endl;
        int count = 0;
        for (const auto& s : container) {
            if (count++ == 5) break;
            cout << "ID: " << s.id << " | Name: " << s.name << " | GPA: " << s.gpa << endl;
        }
        cout << endl;
    };

    auto cmpGPA = [](const Student& a, const Student& b) { return a.gpa > b.gpa; };
    auto cmpID = [](const Student& a, const Student& b) { return a.id < b.id; };
    auto cmpName = [](const Student& a, const Student& b) { return a.name < b.name; };

    sort(arr.begin(), arr.end(), cmpGPA);
    sort(vec.begin(), vec.end(), cmpGPA);
    lst.sort(cmpGPA);
    print5(vec, "Top 5 by GPA (Descending)");

    sort(arr.begin(), arr.end(), cmpID);
    sort(vec.begin(), vec.end(), cmpID);
    lst.sort(cmpID);
    print5(vec, "Top 5 by ID (Ascending)");

    sort(arr.begin(), arr.end(), cmpName);
    sort(vec.begin(), vec.end(), cmpName);
    lst.sort(cmpName);
    print5(vec, "Top 5 by Name (Lexicographical)");

    return 0;
}