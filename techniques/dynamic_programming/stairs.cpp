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
    // How many different ways
    // to climb a staircase of steps n
    // if you can only climb in increments
    // of 1 or 2.
    int n;
    cin >> n;

    // doenst matter how we reached a step.
    // our important state is position
    // this is our only state so dimensionality
    // of the dp array is 1
    
    vector<int> dp (n); // number of ways to get to a step
    dp[0] = 1;
    dp[1] = 1;

    // our transition is as follows:
    // we can get to any state from i-1 or i-2
    // steps away. dp[i] = dp[i-1] + dp[i-2]
    
    for (int i = 2; i < n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout << dp[n-1] << endl;
    
    return 0;
}
