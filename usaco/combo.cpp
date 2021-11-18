/*
ID: dof51
TASK: combo
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

#define DEBUG false

void solve() {
}

int main() {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");

  int n;
  fin >> n;
  vector<int> valid1 (3);
  over(x, valid1)
    fin >> x;
  vector<int> valid2 (3);
  over(x, valid2)
    fin >> x;

  
  auto ring = [&](int num) {
    int r = num % n;
    if (r < 0)
      return r + n;
    else
      return r;
  };

  auto within_tolerance = [&](int a, int b) {
    if (min(ring(a - b), ring(b - a)) <= 2)
      return true;
    else
      return false;
  };

  auto matches = [&](vector<int> a, vector<int> b) {
    for (int i = 0; i < 3; i++) {
      if (!within_tolerance(a[i], b[i]))
          return false;
    }
    return true;
  };

  int ans = 0;
  for (int pos1 = 1; pos1 <= n; pos1++) {
    for (int pos2 = 1; pos2 <= n; pos2++) {
      for (int pos3 = 1; pos3 <= n; pos3++) {
        if (matches(valid1, vector<int> {pos1, pos2, pos3})) {
          ans++;
#if DEBUG
          cout << pos1 << " " << pos2 << " " << pos3 << endl;
#endif
          continue;
        }
        if (matches(valid2, vector<int> {pos1, pos2, pos3})) {
          ans++;
#if DEBUG
          cout << pos1 << " " << pos2 << " " << pos3 << endl;
#endif
          continue;
        }
        
        
      }
    }
  }

  fout << ans << endl;



  return 0;
}

