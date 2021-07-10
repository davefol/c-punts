#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

#define DEBUG false

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> v(n);
  for (auto & x: v)
    cin >> x;

  sort(v.begin(), v.end());

  long long ans = 0;

  for (int i = 0; i < n; i++) {
    ans += upper_bound(v.begin(), v.end(), r - v[i]) - v.begin(); 
    ans -= lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();

    // if v[i] can form a valid pair with itself
    // remove it from the count of pairs
    if (l <= 2 * v[i] && 2 * v[i] <=r)
      ans--;
  }
  cout << ans/2 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

