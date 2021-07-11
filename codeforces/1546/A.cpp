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
  int n;
  cin >> n;
  vector<int> a (n);
  vector<int> b (n);
  for (auto & x : a)
    cin >> x;
  for (auto & x : b)
    cin >> x;
  // solution
  
  vector<int> decr;
  vector<int> incr;
  for (int i = 0; i < n; i++) {
    int diff = b[i] - a[i];
    if (diff > 0) {
      for (int j = 0; j < diff; j++)
        incr.push_back(i);
    } else if (diff < 0) {
      diff *= -1;
      for (int j = 0; j < diff; j++)
        decr.push_back(i);
    }
  }
  if (incr.size() != decr.size()) {
    cout << -1 << endl;
    return;
  }

  cout << decr.size() << endl;
  for (int i = 0; i < decr.size(); i++) {
    cout << decr[i] + 1 << " " << incr[i] + 1 << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

