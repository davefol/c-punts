/*
ID: dof51
TASK: milk
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <fstream>

using namespace std;

#define over(x, v) for (auto & x : v)
#define rep(n) for (int i = 0; i < n; i++)
#define printit(v, s, stream) string sep; over(x, v) { stream << sep << x; sep = s; }

#define DEBUG true

void solve() {
}

int main() {
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");

  int n, m;
  fin >> n >> m;
  vector<pair<int, int>> farmers (m);
  over(x, farmers) {
    fin >> x.first >> x.second;
  }
  sort(farmers.begin(), farmers.end());
  int bought = 0;
  int ans = 0;
  over(x, farmers) {
    if (n - bought > x.second) {
      bought += x.second;
      ans += x.first * x.second;
    } else {
      ans += x.first * (n - bought);
      break;
    }

  }

  fout << ans << endl;

  return 0;
}

