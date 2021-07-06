#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

#define DEBUG true

void solve() {
  int n;
  cin >> n;
  vector<int> d;
  while (n--) {
    int x;
    cin >> x;
    d.push_back(x);
  }


  // The minimum value that an edge
  // from a to b can be is -E(b,a)
  // otherwise there could be a loop
  // between a and b that violates inifnite negative loops

  sort(d.begin(), d.end());


  vector<long long int> difv;
  for (int i = 0; i < d.size() - 1; i++)
    difv.push_back(d[i + 1] - d[i]);


  vector<int> l_include;
  for (int i = 0; i < difv.size(); i++)
    l_include.push_back(i + 1); 

  vector<int> r_include;
  for (int i = 0; i < difv.size(); i++)
    r_include.push_back(difv.size() - i);



  long long int ans = accumulate(difv.begin(), difv.end(), (long long int)0);
  for (int i = 0; i < difv.size(); i++) {
    ans -= difv[i] * l_include[i] * r_include[i];
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

