/*
ID: dof51
TASK: crypt1
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
#define rep(n) for (int i = 0; i < n; i++)
#define printit(v, s, stream) string sep; over(x, v) { stream << sep << x; sep = s; }

#define DEBUG true

void solve() {
}

int main() {
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");

  int n;
  fin >> n;
  set<int> allowed;
  for (int i = 0; i < n; i++) {
    int x;
    fin >> x;
    allowed.insert(x);
  }

  auto nth_digit = [](int num, int n) {
    return int(to_string(num)[n] - '0');
  };

  auto n_digits = [](int num) {
    return to_string(num).size();
  };

  auto contains_only = [](int num, set<int> digits) {
    over(d, to_string(num))
      if (!digits.count(d - '0'))
        return false;
    return true;
  };

  int ans = 0;

  for (int top_num = 111; top_num < 1000; top_num++) {
    if (!contains_only(top_num, allowed))
        continue;
    for (int bottom_num = 11; bottom_num < 100; bottom_num++) {
      if (!contains_only(bottom_num, allowed))
          continue;
      int partial1 = nth_digit(bottom_num, 1) * top_num;
      if (!contains_only(partial1, allowed))
        continue;
      if (n_digits(partial1) != 3)
        continue;
      int partial2 = nth_digit(bottom_num, 0) * top_num;
      if (!contains_only(partial2, allowed))
        continue;
      if (n_digits(partial2) != 3)
        continue;
      int prod = top_num * bottom_num;
      if (!contains_only(prod, allowed))
        continue;
      if (n_digits(prod) != 4)
        continue;
      ans++;

    }
  }

  fout << ans << endl;


  return 0;
}

