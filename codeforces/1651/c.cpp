#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>

#define DEBUG 1

using namespace std;

int findmin(int64_t x, vector<int64_t> v) {
    vector<int64_t> diff (v.size());
    transform(v.begin(), v.end(), diff.begin(), [x](auto y){return abs(x - y);});
    int mineli = distance(diff.begin(), min_element(diff.begin(), diff.end()));
    return mineli;
}

void solve(int64_t n, vector<int64_t> a, vector<int64_t> b) {
    vector<pair<int, int>> combos; // first is a, second is b

    combos.push_back(make_pair(
        0, findmin(a[0], b)
    ));
    combos.push_back(make_pair(
        a.size() - 1, findmin(a[a.size() - 1], b)
    ));
    combos.push_back(make_pair(
        findmin(b[0], a), 0
    ));
    combos.push_back(make_pair(
        findmin(b[b.size() - 1], a), b.size() - 1
    ));

    sort(combos.begin(), combos.end(), [](auto x, auto y){
    if (x.first != y.first)
        return x.first < y.first;
    return x.second < y.second;
    });

    combos.erase(unique(combos.begin(), combos.end()), combos.end());

#if DEBUG
    for (auto it : combos)
        cout << "(" << it.first << ", " << it.second << ") ";
    cout << endl;
#endif

    vector<int64_t> combos_diff (combos.size());
    transform(combos.begin(), combos.end(), combos_diff.begin(), [a, b](auto x){
        return abs(a[x.first] - b[x.second]); 
    });

    auto ans = accumulate(combos_diff.begin() , combos_diff.end(), (uint64_t)0);
    cout << ans << endl;
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;
       vector<int64_t> a (n);
       vector<int64_t> b (n);
       for (auto &it : a)
           cin >> it;
       for (auto &it : b)
           cin >> it;
       solve(n, a, b);
    }
    return 0;
}
