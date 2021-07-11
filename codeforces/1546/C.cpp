#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;

#define DEBUG true

void solve() {
  int n;
  cin >> n;
  vector<int> v (n);
  for (auto & x : v)
    cin >> x;
  map<int, int> count_even;
  map<int, int> count_odd;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      count_even[v[i]]++;
    else
      count_odd[v[i]]++;
  }
  sort(v.begin(), v.end());
  map<int, int> count_even_sorted;
  map<int, int> count_odd_sorted;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      count_even_sorted[v[i]]++;
    else
      count_odd_sorted[v[i]]++;
  }
  string ans = "YES";
  for (auto const& [k,v] : count_even_sorted) {
    if (v != count_even[k]) {
      ans = "NO";
      break;
    }
  }

  if (ans == "NO") {
    cout << ans << endl;
    return;
  }
  for (auto const& [k,v] : count_odd_sorted) {
    if (v != count_odd[k]) {
      ans = "NO";
      break;
    }
  }

 cout << ans << endl;
 return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

