/*
ID: dof51
TASK: transform
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

#define vvc vector<vector<char>>
#define over(x, v) for (auto & x : v)
#define rep(i, n) for (int i = 0; i < n; i++)
#define printit(v, s, stream) string sep; over(x, v) { stream << sep << x; sep = s; }

#define DEBUG true

void solve() {
}

int main() {
  ofstream fout ("transform.out");
  ifstream fin ("transform.in");

  int n;
  fin >> n;

  // row major
  vector<vector<char>> a;
  vector<vector<char>> b;

  for (int i = 0; i < n; i++) {
    vector<char> row (n);
    over(x, row) {
      fin >> x;
    }
    a.push_back(row);
  }
  for (int i = 0; i < n; i++) {
    vector<char> row (n);
    over(x, row) {
      fin >> x;
    }
    b.push_back(row);
  }

  auto show_mat = [](vector<vector<char>> mat) {
    over(row, mat) {
      over(x, row) {
        cout << x;
      }
      cout << endl;
    }
    cout << endl;
  };

  auto mat_equal = [&](vector<vector<char>> a, vector<vector<char>> b) {
    for (int row = 0; row < n; row++)
      for (int val = 0; val < n; val++)
        if (a[row][val] != b[row][val])
          return false;
    return true;
  };

  auto transpose = [&](vvc inp) {
    vvc out (n, vector<char>(n));
    for (int col = 0; col < n; col++) {
      for(int row = 0; row < n; row++) {
        out[col][row] = inp[row][col];
      }
    }
    return out;
  };

  auto reflect_vertical = [](vvc inp) {
    vvc out = inp;
    reverse(out.begin(), out.end());
    return out;
  };

  auto rot90 = [&](vvc inp) {
    return transpose(reflect_vertical(inp));
  };

  auto rot180 = [&](vvc inp) {
    return rot90(rot90(inp));
  };

  auto rot270 = [&](vvc inp) {
    return rot180(rot90(inp));
  };

  auto reflect_horizontal = [&](vvc inp) {
    return transpose(reflect_vertical(transpose(inp)));
  };

  if (mat_equal(rot90(a), b)) {
    fout << "1" << endl;
    return 0;
  }

  if (mat_equal(rot180(a), b)) {
    fout << "2" << endl;
    return 0;
  }

  if (mat_equal(rot270(a), b)) {
    fout << "3" << endl;
    return 0;
  }

  if (mat_equal(reflect_horizontal(a), b)) {
    fout << "4" << endl;
    return 0;
  }

  if (mat_equal(rot90(reflect_horizontal(a)), b)) {
    fout << "5" << endl;
    return 0;
  }

  if (mat_equal(rot180(reflect_horizontal(a)), b)) {
    fout << "5" << endl;
    return 0;
  }

  if (mat_equal(rot270(reflect_horizontal(a)), b)) {
    fout << "5" << endl;
    return 0;
  }

  if (mat_equal(a,b)) {
    fout << "6" << endl;
    return 0;
  }

  fout << "7" << endl;
  return 0;
}

