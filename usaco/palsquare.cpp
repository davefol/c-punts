/*
ID: dof51
TASK: palsquare
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
  ofstream fout ("palsquare.out");
  ifstream fin ("palsquare.in");

  int base;
  fin >> base;

  auto is_pal = [](string s) {
    string rev = s;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++)
      if (s[i] != rev[i])
        return false;
    return true;
  };

  auto log_base = [](int x, int base) {
    return log(x) / log(base);
  };

  auto as_digit = [](int x) {
    if (x < 10)
      return char(x + 48);
    else
      return char(x + 55);
  };

  auto to_base = [&](int x, int base) {
    string out = "";
    int highest_pow = log_base(x, base);
    int left_over = x;
    for (int place = highest_pow; place >= 0; place--) {
      int digit = left_over / pow(base, place);
      left_over -= digit * pow(base, place);
      out.push_back(as_digit(digit));
    }
    return out;
  };

  for (int i = 1; i <= 300; i++) {
    int sq = i * i;
    string as_base = to_base(sq, base);
    if (is_pal(as_base)) {
      fout << to_base(i, base) << " " << as_base << endl; 
    }
  }

  return 0;
}

