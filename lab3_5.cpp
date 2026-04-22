#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <numeric>

using namespace std;
using namespace std::chrono;

int main() {
    vector<int> v(100000, 1);
    list<int> l(100000, 1);

    auto t1 = high_resolution_clock::now();
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    auto t2 = high_resolution_clock::now();
    cout << "Vector sum: " << duration<double>(t2 - t1).count() << "s" << endl;

    t1 = high_resolution_clock::now();
    v[0]; 
    v[25000];
    v[50000];
    v[75000];
    v[99999];
    t2 = high_resolution_clock::now();
    cout << "Vector access: " << duration<double>(t2 - t1).count() << "s" << endl;

    t1 = high_resolution_clock::now();
    v.insert(v.begin() + 50000, 100, 42);
    t2 = high_resolution_clock::now();
    cout << "Vector insert: " << duration<double>(t2 - t1).count() << "s" << endl;

    t1 = high_resolution_clock::now();
    l.insert(next(l.begin(), 50000), 100, 42);
    t2 = high_resolution_clock::now();
    cout << "List insert: " << duration<double>(t2 - t1).count() << "s" << endl;

    return 0;
}