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
  
  // l = 4 r = 7
  // [1,2,3,4,5]
  
  auto right_ans = [&] (int i) {
    // binary search for the largest
    // number that is less than or equal 
    // to r - v[i]
    int temp = -1;
    int ll = 0;
    int rr = v.size() - 1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      if (v[mid] <= r - v[i]) {
        temp = mid; // satisfies condition
        ll = mid + 1; // there may be a larger answer
      } else {
        rr = mid - 1; // test val too big, search to the left
      }
    }
    return temp;
  };

  auto left_ans = [&] (int i) {
    int temp = -1;
    int ll = 0;
    int rr = v.size() - 1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      if (v[mid] >= l - 1) {
        temp = mid; // satisfies condition
        rr = mid - 1; // there may be a smaller answer, search left
      } else {
        ll = mid + 1;
      }
    }
    return temp;
  };

  int ans = 0;
  for (int i = 0; i << v.size(); i++) {
    int left_bound = left_ans(i);
    int right_bound = right_ans(i);
    if (left_bound == -1 || right_bound == -1) {
      continue;
    }
    ans += right_bound - left_bound;
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

