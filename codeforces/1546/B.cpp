#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

#define DEBUG false

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s (n + n - 1);
  for (auto & x : s)
    cin >> x;
  string ans;
  for (int i = 0; i < m; i++) {
    map<char, int> count;
    for (int j = 0; j < n + n - 1; j++) {
      count[s[j][i]]++;
    }
    for (auto const& [k, v] : count) {
      if (v % 2 != 0) {
        ans.push_back(k);
        break;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

