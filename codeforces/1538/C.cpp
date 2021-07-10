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
  cin >> n;
  cin >> l;
  cin >> r;
  vector<int> v (n);
  for (auto & x : v)
    cin >> x;
  
  sort(v.begin(), v.end());

  // count number of pairs ai + aj <= r
  // count number of pairs ai + aj <= l - 1
  
  // l = 5 r = 8
  // [1,2,3,4,5]
  // 1 (5, 4, 3, 2) - (3, 2) = 2
  // 2 (5, 4, 3) - () = 3
  // 3 (5, 4) - () = 2
  // 4 () - () = 0
  // 5 () - () = 0
  // ans = 7
  //
  // l = 4, r = 7
  // [1, 2, 5]
  // 1 (5, 2) - (2) = 1
  // 2 (5) - () = 1
  // ans = 2

#if DEBUG
  cout << "l = " << l << endl;
  cout << "r = " << r << endl;
  for(auto x : v)
    cout << x << " ";
  cout << endl;
#endif
  
  long long ans = 0;
  for (int i = 0; i < v.size(); i++) {
    // right bound
    // greatest number <= r - v[i]
    int r_bound = -1;
    int ll = 0;
    int rr = v.size() - 1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      if (v[mid] <= r - v[i]) {
        r_bound = mid;
        ll = mid + 1;
      } else {
        rr = mid - 1;
      }
    }
    int r_bound_pairs;
    if (r_bound == -1)
      r_bound_pairs = 0;  
    else
      r_bound_pairs = r_bound - i;

    // left bound
    // greatest number <= l - v[i] - 1
    int l_bound = -1;
    ll = i;
    rr = v.size() - 1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      if (v[mid] <= l - v[i] - 1) {
        l_bound = mid;
        ll = mid + 1;
      } else {
        rr = mid - 1;
      }
    }
    int l_bound_pairs;
    if (l_bound == -1)
      l_bound_pairs = 0;
    else
      l_bound_pairs = l_bound - i;

    if (r_bound_pairs > l_bound_pairs)
      ans += r_bound_pairs - l_bound_pairs;

#if DEBUG
    cout << "i = " << i << endl;
    cout << "v[i] = " << v[i] << endl;
    cout << "l_bound = " << l_bound << endl;
    cout << "r_bound = " << r_bound << endl;
    cout << "ans = " << ans << endl;
    cout << endl;
#endif

  }

  cout << ans << endl;
  
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

