/*
ID: dof51
TASK: wormhole
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
#include <set>

using namespace std;

#define over(x, v) for (auto & x : v)
#define rep(i, n) for (int i = 0; i < n; i++)
#define printit(v, s, stream) string sep; over(x, v) { stream << sep << x; sep = s; }

#define DEBUG true

vector<vector<pair<int, int>>> pairings(set<int> available, vector<pair<int, int>> suffix) {
  // select first eleemnt 
  auto p1 = *available.begin();
  available.erase(available.begin());

  // loop over remaining elements
  vector<vector<pair<int, int>>> out;
  for (auto & p2 : available) {
    auto available_arg = available;
    available_arg.erase(p2);
    auto suffix_arg = suffix;
    suffix_arg.push_back(make_pair(p1, p2));
    auto sub_pairings = pairings(available_arg, suffix_arg);
    for (int i = 0; i < sub_pairings.size(); i++) {
      out.push_back(sub_pairings[i]);
    }
  }
  
}

void solve() {
}

int main() {
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");

  int n;
  fin >> n;
  vector<pair<int, int>> wormholes (n);
  over(x, wormholes)
    fin >> x.first >> x.second;


  return 0;
}

