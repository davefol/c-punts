/*
ID: dof51
TASK: gift1
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

#define DEBUG false

void solve() {
}

int main() {
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");

  map<string, int> money;
  int n;
  fin >> n;
  vector<string> names;
  while(n--) {
    string name;
    fin >> name;
    money[name] = 0;
    names.push_back(name);
  }

  string giver;
  while(fin >> giver) {
    int total_gift, n_receivers;
    fin >> total_gift >> n_receivers;
    int gift = 0;
    int left_over = 0;
    if (n_receivers > 0) {
      gift = total_gift / n_receivers;
      left_over = total_gift % n_receivers;
    }
    money[giver] = money[giver] - total_gift + left_over;
#if DEBUG
    cout << giver << " " << total_gift << " " << gift << " " << left_over << endl;
#endif
    while(n_receivers--) {
      string receiver;
      fin >> receiver;
      money[receiver] += gift;
#if DEBUG
      cout << "\t" << giver << " gave " << gift << " to " << receiver << endl;
#endif
    }
#if DEBUG
    for (auto const& x: money)
      cout << x.first << ": " << x.second << ", ";
    cout << endl;
#endif
  }

  for (auto name : names)
    fout << name << " " << money[name] << endl;


  return 0;
}

