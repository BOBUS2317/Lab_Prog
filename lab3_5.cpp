#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <iterator>
#include <random>

using namespace std;
using namespace std::chrono;

int main() {
    const int N = 100000;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    vector<int> v(N);
    list<int> l;
    array<int, N> a;

    for (int i = 0; i < N; ++i) {
        int val = dis(gen);
        v[i] = val;
        l.push_back(val);
        a[i] = val;
    }

    auto measure_sum = [](auto& container) {
        auto t1 = high_resolution_clock::now();
        volatile long long sum = accumulate(container.begin(), container.end(), 0LL);
        auto t2 = high_resolution_clock::now();
        return duration<double>(t2 - t1).count();
    };

    auto measure_access = [](auto& container) {
        vector<int> indices = {0, 25000, 50000, 75000, 99999};
        auto t1 = high_resolution_clock::now();
        for (int idx : indices) {
            auto it = container.begin();
            advance(it, idx);
            volatile int val = *it;
        }
        auto t2 = high_resolution_clock::now();
        return duration<double>(t2 - t1).count();
    };

    auto measure_push_back = [](auto& container) {
        auto t1 = high_resolution_clock::now();
        for(int i = 0; i < 1000; ++i) container.push_back(42);
        auto t2 = high_resolution_clock::now();
        return duration<double>(t2 - t1).count();
    };

    auto measure_ins_mid = [](auto& container) {
        auto t1 = high_resolution_clock::now();
        auto it = next(container.begin(), 50000);
        container.insert(it, 100, 42);
        auto t2 = high_resolution_clock::now();
        return duration<double>(t2 - t1).count();
    };

    auto measure_erase_mid = [](auto& container) {
        auto t1 = high_resolution_clock::now();
        auto it_start = next(container.begin(), 50000);
        auto it_end = next(it_start, 100);
        container.erase(it_start, it_end);
        auto t2 = high_resolution_clock::now();
        return duration<double>(t2 - t1).count();
    };

    double v_res[5], l_res[5], a_res[5];

    v_res[0] = measure_sum(v);   l_res[0] = measure_sum(l);   a_res[0] = measure_sum(a);
    v_res[1] = measure_access(v); l_res[1] = measure_access(l); a_res[1] = measure_access(a);
    v_res[2] = measure_push_back(v); l_res[2] = measure_push_back(l); a_res[2] = -1;
    v_res[3] = measure_ins_mid(v); l_res[3] = measure_ins_mid(l); a_res[3] = -1;
    v_res[4] = measure_erase_mid(v); l_res[4] = measure_erase_mid(l); a_res[4] = -1;

    string ops[] = {"Sequential Sum", "Random Access", "End Insert", "Middle Insert", "Middle Erase"};
    
    cout << "\n" << setfill('=') << setw(70) << "=" << endl;
    cout << setfill(' ') << "|" << setw(20) << left << " Operation" 
         << "|" << setw(15) << left << " Vector (s)" 
         << "|" << setw(15) << left << " List (s)" 
         << "|" << setw(15) << left << " Array (s)" << "|" << endl;
    cout << setfill('-') << setw(70) << "-" << endl;
    cout << setfill(' ') << fixed << setprecision(6);

    for (int i = 0; i < 5; ++i) {
        cout << "|" << setw(20) << left << ops[i] << "|" << setw(15) << left << v_res[i] << "|" << setw(15) << left << l_res[i];
        if (a_res[i] < 0) cout << "|" << setw(15) << left << "N/A" << "|" << endl;
        else cout << "|" << setw(15) << left << a_res[i] << "|" << endl;
    }
    cout << setfill('=') << setw(70) << "=" << endl;
    return 0;
}