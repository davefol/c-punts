#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>

#define N 100

using namespace std;

int main() {
    int k;
    cin >> k;
    k--;
    vector<int> dp (N);
    dp[0] = 1;
    dp[1] = 1;
    for (int  i = 2; i < N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[k] << endl;
    return 0;
}
