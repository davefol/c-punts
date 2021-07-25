/*
ID: dof51
TASK: ride
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
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");

  string comet, group;
  fin >> comet >> group;

  auto alpha_mult = [](int a, char b) {
    return a * int(b - 'A' + 1);
  };

  int comet_num = accumulate(comet.begin(), comet.end(), 1, alpha_mult);
  int group_num = accumulate(group.begin(), group.end(), 1, alpha_mult);

  if (comet_num % 47 == group_num % 47)
    fout << "GO" << endl;
  else
    fout << "STAY" << endl;


  return 0;
}

