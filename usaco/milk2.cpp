/*
ID: dof51
TASK: milk2
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
#define rep(i, n) for (int i = 0; i < n; i++)
#define printit(v, s, stream) string sep; over(x, v) { stream << sep << x; sep = s; }

#define DEBUG false 

void solve() {
}

int main() {
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");

  int n;
  fin >> n;

  vector<pair<int, int>> periods (n);
  over(x, periods) {
    fin >> x.first;
    fin >> x.second;
  }

  sort(periods.begin(), periods.end());

  int chunk_start = periods[0].first;
  int chunk_end = periods[0].second;
  int chunk_size = chunk_end - chunk_start;
  int max_chunk_size = chunk_size;
  int max_gap = 0;
  rep(i, periods.size() - 1) {
#if DEBUG
    cout << "\t\t" << chunk_start << " " << chunk_end << endl;
#endif
    if (chunk_end >= periods[i+1].first) {
      chunk_end = max(periods[i+1].second, chunk_end);
      max_chunk_size = max(chunk_end - chunk_start, max_chunk_size);
    } else if (periods[i+1].second <= chunk_end) {
      continue;
    } else {
#if DEBUG
      cout << "\t" << i << " " << periods[i].second << " " << chunk_end << endl;
#endif
      max_gap = max(periods[i+1].first - chunk_end, max_gap);
      chunk_start = periods[i+1].first;
      chunk_end = periods[i+1].second;
    }
  }
  max_chunk_size = max(max_chunk_size, periods[n-1].second - periods[n-1].first);

  fout << max_chunk_size << " " << max_gap << endl;



  return 0;
}

