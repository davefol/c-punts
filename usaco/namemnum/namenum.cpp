/*
ID: dof51
TASK: namenum
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
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in");
  ifstream din ("dict.txt");

  string code;
  fin >> code;

  map<char, char> encoding {
    {'A', '2'},
    {'B', '2'},
    {'C', '2'},
    {'D', '3'},
    {'E', '3'},
    {'F', '3'},
    {'G', '4'},
    {'H', '4'},
    {'I', '4'},
    {'J', '5'},
    {'K', '5'},
    {'L', '5'},
    {'M', '6'},
    {'N', '6'},
    {'O', '6'},
    {'P', '7'},
    {'R', '7'},
    {'S', '7'},
    {'T', '8'},
    {'U', '8'},
    {'V', '8'},
    {'W', '9'},
    {'X', '9'},
    {'Y', '9'},
  };

  string entry;
  bool no_valid = true;
  while(din >> entry) {
    if (code.size() == entry.size()) {
      bool matches = true;
      for (int i = 0; i < code.size(); i++) {
        if (encoding[entry[i]] != code[i]) {
          matches = false;
          break;
        }
      }
      if (matches) {
        fout << entry << endl;
        no_valid = false;
      }
    }
  }
  if (no_valid)
    fout << "NONE" << endl;

  return 0;
}

