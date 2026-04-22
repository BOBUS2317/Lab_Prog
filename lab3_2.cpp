#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    vector<int> vec;
    list<int> lst;

    for (int i = 0; i < 100; ++i) {
        int val = rand() % 1000 + 1;
        vec.push_back(val);
        lst.push_back(val);
    }

    vec.insert(vec.begin() + 50, 999);
    lst.insert(next(lst.begin(), 50), 999);

    vec.erase(vec.begin() + 25);
    lst.erase(next(lst.begin(), 25));

    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x > 500; }), vec.end());
    lst.remove_if([](int x) { return x > 500; });

    cout << "Vector remaining: " << vec.size() << endl;
    cout << "List remaining: " << lst.size() << endl;

    return 0;
}