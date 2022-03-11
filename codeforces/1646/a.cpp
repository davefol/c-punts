#include <iostream>
#include <vector>
#include <math.h>
#include <cstdint>

#define DEBUG 0

using namespace std;

void solve(uint64_t n, uint64_t s) {
#if DEBUG
    cout << n << " " << s << endl;
#endif
    uint64_t n_increment = pow(n, 2) - (n - 1);
    uint64_t max_n = pow(n, 2) * (n + 1);
    uint64_t n_floor = (n-1) * (n+1);

    if (s <= n_floor) {
        cout << 0 << endl;
        return;
    }
    long long ans  = (n+1) - ((max_n - s) / n_increment);
    cout << ans << endl;


    return;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        uint64_t n, s;
        cin >> n >> s;
        solve(n, s);
    }
    return 0;
}
