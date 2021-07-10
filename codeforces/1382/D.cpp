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

bool subset_sum(vector<int> v, int n, int target, vector<vector<int>> &memo) {
  if (target == 0)
    return true;

  if (n == 0)
    return false;

  if (memo[n][target] != -1)
    return memo[n][target];


  if (v[n-1] > target) {
    memo[n][target] = subset_sum(v, n-1, target, memo);
    return memo[n][target];
  }

  bool exclusion = subset_sum(v, n-1, target, memo);
  bool inclusion = subset_sum(v, n-1, target - v[n-1], memo);
  memo[n][target] = inclusion || exclusion;
  return memo[n][target];
}

void solve() {
  int n;
  cin >> n;
  vector<int> v (2*n);
  for (auto & x : v)
    cin >> x;
  v.push_back(-1);

  // check for "clumps"
  // [3], 2, [6], 1, 5, [7], [8], 4
  int test_val = v[0];
  int clump_size = 1;
  vector<int> clumps;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] == -1) {
      clumps.push_back(clump_size);
      break;
    }
    if (v[i] < test_val)
      clump_size++;
    else {
      clumps.push_back(clump_size);
      test_val = v[i];
      clump_size = 1;
    }
  }

#if DEBUG
  for (auto x : v)
    cout << x << " ";
  cout << endl;
  for (auto x : clumps)
    cout << x << " ";
  cout << endl;
#endif

  vector<vector<int>> memo;
  for (int row = 0; row < clumps.size() + 1; row++) {
    vector<int> _memo;
    for (int col = 0; col < n + 1; col++) {
      _memo.push_back(-1);
    }
    memo.push_back(_memo);
  }

  if (subset_sum(clumps, clumps.size(), n, memo))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

