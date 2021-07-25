/*
ID: dof51
TASK: barn1
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
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");

  int m, s, c;
  fin >> m >> s >> c;
  vector<bool> stalls (s);
  while (c--) {
    int x;
    fin >> x;
    stalls[x-1] = true;
  }

  // find all runs
  bool in_a_run = false;
  vector<int> run_start;
  vector<int> run_end;
  for (int j = 0; j < s; j++) {
    if (!stalls[j] && !in_a_run) {
      run_start.push_back(j);
      in_a_run = true;
    } else if (stalls[j] && in_a_run) {
      run_end.push_back(j);
      in_a_run = false;
    }
  }
  if (in_a_run) {
    run_end.push_back(s);
  }

  vector<int> run_lens;
  for (int i = 0; i < run_start.size(); i++) {
    run_lens.push_back(run_end[i] - run_start[i]);  
  }

  vector<pair<int, pair<int, int>>> runs;
  
  for (int i = 0; i < run_lens.size(); i++) {
    pair<int, int> run_range = make_pair(run_start[i], run_end[i]);
    pair<int, pair<int, int>> run = make_pair(run_lens[i], run_range);
    runs.push_back(run);
  }


  int ans = s;
  
  // remove edges
  for (int i = 0; i < runs.size(); i++) {
    // run begin 0 then remove
    if (runs[i].second.first == 0) {
      ans -= runs[i].first;
      runs[i].first = -1;
    }
    if (runs[i].second.second == s) {
      ans -= runs[i].first;
      runs[i].first = -1;
    }
  }
  
  // now runs are in order
  sort(runs.begin(), runs.end());

#if DEBUG
  for (int i = 0; i < runs.size(); i++) {
    cout << runs[i].second.first + 1<< " " << runs[i].second.second + 1 << " " << runs[i].first << endl;
  }
#endif

  m--;
  while(m--) {
    if (runs[runs.size() - 1].first == -1)
      break;
    ans -= runs[runs.size()-1].first;
    runs.pop_back();
  }

  fout << ans << endl;
  return 0;
}

