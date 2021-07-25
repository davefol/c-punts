/*
ID: dof51
TASK: beads
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <fstream>

using namespace std;

#define over(x, v) for (auto & x : v)
#define rep(i, n) for (int i = 0; i < n; i++)
#define printit(v, s, stream) string sep; over(x, v) { stream << sep << x; sep = s; }

#define DEBUG false

void solve() {
}

int main() {
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");

  int n;
  fin >> n;

  string beads;
  fin >> beads;

  int ans = -1;

  bool one_color = true;
  char first_color = beads[0];
  over(c, beads)
    if (c != first_color)
      one_color = false;
  if (one_color) {
    fout << n << endl;
    return 0;

  }


  for (int i = 0; i < n; i++) {
    vector<char> flat_beads;
    for (int j = 0; j < n; j++)
      flat_beads.push_back(beads[(i + j) % n]);
    flat_beads.insert(flat_beads.end(), flat_beads.begin(), flat_beads.end());

    auto right_non_white = [&](int idx) {
      for (int i = idx; i < n*2; i++) {
        if (flat_beads[i] != 'w')
          return flat_beads[i];
      }
      return 'w';
    };

    auto left_non_white = [&](int idx) {
      for (int i = idx; i >= 0; i--) {
        if (flat_beads[i] != 'w')
          return flat_beads[i];
      }
      return 'w';
    };

    char left_color = left_non_white(n - 1);
    char right_color = right_non_white(n);

    int left_extent = n - 1;
    while (left_extent >=0 && (flat_beads[left_extent] == left_color || flat_beads[left_extent] == 'w'))
      left_extent--;

    int right_extent = n;
    while (right_extent < n * 2 && (flat_beads[right_extent] == right_color || flat_beads[right_extent] == 'w'))
        right_extent++;
#if DEBUG
    for (int k = 0; k < n*2; k++) {
      if (k == left_extent || k == right_extent)
        cout << "[" << flat_beads[k] << "]";
      else
        cout << flat_beads[k];

      if (k == n - 1)
        cout << "|";
    }
    cout << endl;
#endif

    ans = max(ans, right_extent - left_extent - 1);
    ans = min(ans, n);
  }
  fout << ans << endl;
  return 0;
}

