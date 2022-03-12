#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>

using namespace std;

void solve(int n, int d, vector<int> a) {
    auto get_minbreak = [a, n](){
        int m = a[0] - 1;
        int mi = 0;
        for (int i = 1; i < n; i++) {
            int test = a[i] - a[i-1] - 1;
            if (m > test) {
                mi = i;
                m = test;
            }
        }
        return mi;
    };
    int minbreak = get_minbreak();


    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a (n);
        for (auto &it: a)
            cin >> it;
        solve(n, d, a);
    }
    return 0;
}
