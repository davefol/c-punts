#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>

#define DEBUG 0

using namespace std;

void solve(uint32_t n, vector<uint64_t> a) {
    sort(a.begin(), a.end());

    vector<uint64_t> prefix_sum (n, 0);
    partial_sum(a.begin(), a.end(), prefix_sum.begin());

    vector<uint64_t> suffix_sum (n, 0);
    partial_sum(a.rbegin(), a.rend(), suffix_sum.begin());

#if DEBUG
    cout << "a: ";
    for (auto it: a)
        cout << it << " ";
    cout << endl;

    cout << "ps: ";
    for (auto it: prefix_sum)
        cout << it << " ";
    cout << endl;

    cout << "ss: ";
    for (auto it: suffix_sum)
        cout << it << " ";
    cout << endl;
#endif

    for (uint32_t k=0; k < n/2; k++) {
        if (prefix_sum[k+1] < suffix_sum[k]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

}

int main() {
    uint32_t t;
    cin >> t;
    while(t--) {
        uint32_t n;
        cin >> n;
        vector<uint64_t> a (n);
        for (auto &it : a)
            cin >> it;
        solve(n, a);
    }
    return 0;
}
