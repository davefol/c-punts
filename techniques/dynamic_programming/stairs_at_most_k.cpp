#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>

using namespace std;


int main() {
    // How many ways can you
    // climb the stairs,
    // taking 1 or 2 steps
    // in at most k moves?
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n);
    for (auto &it : dp)
        it = vector<int>(k);

    for (auto &it : dp[0])
        it = 1;
    for (auto &it : dp[1])
        it = 1;
    dp[0][0] = 0;
    dp[1][0] = 0;

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-2][j-1];
        }
    }

    int ans = accumulate(dp[n-1].begin(), dp[n-1].begin() + k - 1, 0);
    cout << ans << endl;

    return 0;
}
