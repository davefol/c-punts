#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>

#define DEBUG 0

using namespace std;

void solve(uint64_t n, vector<uint64_t> factorials) {
    uint32_t ans = __builtin_popcountll(n);
    for (uint32_t i = 0; i < 1<<factorials.size(); i++) {
        // add up the factorials which are set
        uint64_t fact_sum = 0;
        uint32_t fact_count = 0;
        for (uint32_t k = 0; k < factorials.size(); k++) {
            if (i & (1 << (k - 1))) {
                fact_sum += factorials[k];
                fact_count++;
            }
            uint64_t rest = n - fact_sum;
            uint32_t total_count = fact_count + __builtin_popcountll(rest);
            ans = min(total_count, ans);
        }
    }
    cout << ans << endl;
}

vector<uint64_t> get_factorials(uint64_t m) {
    vector<uint64_t> factorials;

    uint64_t i = 2;
    uint64_t x = 1;
    while (x < m) {
        factorials.push_back(x);
        x *= i;
        i++;
    }
    return factorials;
}

int main() {

    vector<uint64_t> factorials = get_factorials(pow(10, 12));
#if DEBUG
    cout << "factorials.size() == " << factorials.size() << endl;
#endif

    uint32_t t;
    cin >> t;
    while(t--) {
        uint64_t n;
        cin >> n;
        solve(n, factorials);
    }
    return 0;
}
