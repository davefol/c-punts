/*
ID: dof51
TASK: friday
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
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");


  // jan, feb, march, april, may, june, july, august, september, oct, nov, dec
  // 0,    1,     2,    3,    4,    5,   6,      7,       8,      9,   10,  11
  //                    30         30                    30            30
  
  vector<int> weekdays (7, 0);

  int n;
  fin >> n;

  auto n_days = [](int year, int month) {
    if (month == 3 || month == 5 || month == 8 || month == 10)
      return 30;
    if (month == 1)
      if (year % 100 == 0) // century year
        if (year % 400 == 0) // century leap year
          return 29;
        else
          return 28;
      else // non century year
        if (year % 4 == 0) // leap year
          return 29;
        else // regular year
          return 28;
    else
      return 31;
  };

  int weekday = 2;
  for (int year = 1900; year < 1900 + n; year++) {
    for (int month = 0; month < 12; month++) {
      for (int day = 0; day < n_days(year, month); day++) {
        if (day == 12)
          weekdays[weekday]++;
        weekday = (weekday + 1) % 7;
      }
    }
  }


  printit(weekdays, " ", fout)
  fout << endl;


  return 0;
}

