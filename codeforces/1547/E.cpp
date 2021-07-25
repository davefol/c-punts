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

#define DEBUG false

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> pos (k);
  vector<int> temp (k);
  for (auto & x: pos)
    cin >> x;
  for (auto & x : temp)
    cin >> x;
  vector<long long> cells (n, INT_MAX);
  for (int i = 0; i < k; i++)
    cells[pos[i] - 1] = temp[i];

  vector<long long> L (n, INT_MAX);
  vector<long long> R (n, INT_MAX);
  long long p = INT_MAX;
  for (int i = 0; i < n; i++) {
    p = min(p + 1, cells[i]);
    L[i] = p;
  }
  p = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
    p = min(p + 1, cells[i]);
    R[i] = p;
  }
  
  for (int i = 0; i < n; i++)
    cout <<  min(L[i], R[i]) << " ";
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

