#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int id;
    double gpa;
};

int main() {
    vector<Student> students;
    for (int i = 0; i < 1000; ++i) {
        students.push_back({"Student" + to_string(i), rand() % 10000, (rand() % 40 + 10) / 10.0});
    }

    auto print5 = [&](const string& label) {
        cout << label << ":" << endl;
        for (int i = 0; i < 5; ++i) cout << students[i].name << " " << students[i].gpa << endl;
    };

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.gpa > b.gpa; });
    print5("By GPA");

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.id < b.id; });
    print5("By ID");

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.name < b.name; });
    print5("By Name");

    return 0;
}