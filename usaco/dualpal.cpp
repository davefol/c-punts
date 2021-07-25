/*
ID: dof51
TASK: dualpal
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
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");

  int n, s;
  fin >> n >> s;
  int num_found = 0;
  int test_num = s + 1;
  while(num_found < n) {
    int palindrome_count = 0;
    for (int base = 2; base <= 10; base++) {
      string base_rep;
      int remainder = test_num;
      while (remainder > 0) {
        int digit = remainder % base;
        base_rep.push_back(digit);
        remainder = remainder / base;
      }
      string base_rep_rev = base_rep;
      reverse(base_rep_rev.begin(), base_rep_rev.end());
      int str_eq = true;
      for (int i = 0; i < base_rep.size(); i++) {
        if (base_rep_rev[i] != base_rep[i]) {
          str_eq = false;
          break;
        }
      }
      if (str_eq) {
        palindrome_count++;
      }
      if (palindrome_count >= 2) {
        break;
      }
    }
    if (palindrome_count >= 2) {
      num_found++;
      fout << test_num << endl;
    }
    test_num++;
  }


  return 0;
}

