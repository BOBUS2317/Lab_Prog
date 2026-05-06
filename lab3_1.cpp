#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int x : arr) cout << x << " "; cout << endl;
    for (int x : vec) cout << x << " "; cout << endl;
    for (int x : lst) cout << x << " "; cout << endl;

    arr[5] = 100;
    vec[5] = 100;
    auto it = lst.begin();
    advance(it, 5);
    *it = 100;

    vec.push_back(11);
    lst.push_back(11);

    cout << "Sizes: " << arr.size() << " " << vec.size() << " " << lst.size() << endl;
    cout << "Array: " << arr[0] << " " << arr.back() << endl;
    cout << "Vector: " << vec[0] << " " << vec.back() << endl;
    cout << "List: " << lst.front() << " " << lst.back() << endl;

    return 0;
}