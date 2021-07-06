#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

#define DEBUG false

void solve() {
  int l, r;
  cin >> l;
  cin >> r;
  // if suffix is 9
  //    changed digits is 2
  // if suffix is 99
  //    changed digits is 3
  // if the suffix is anything except 9
  //    changed digits is 1

  // how many numbers have a suffix with 9 between 1 and 100?
  // 9, 19, 29, 39, 49, 59, 69, 79, 89, 99
  // 9 with '9' suffix and 1 with '99' suffix
  // 99 additions - 10 which are only 1 change + 9 with two changes and 1 with 3 changes
  // 89 + 18 + 3 = 110
  
  // [1, 99]
  //    9 with suffix '9'
  // [1, 999]
  //    90 with suffix '9'
  //    9 with suffix '99'
  // ...
  

  auto countSuffix = [](int x, int numNines) {
    // start at end of number
    string digits = to_string(x);
    reverse(digits.begin(), digits.end());
    int out = 0;
    for (int i=numNines; i < digits.size(); i++)
    {
      if (i - numNines == 0)
        out += digits[i] - '0';
      else 
        out += (digits[i] - '0') * 9 * pow(10, i - numNines - 1);
    }
    return out;
  };

  auto countAllSuffixes = [&](int x) {
    vector<int> out (11, 0);
    for (int i = 1; i < 11; i++)
      out[i] = countSuffix(x, i);
    return out;
  };

  vector<int> leftNines = countAllSuffixes(l);
  vector<int> rightNines = countAllSuffixes(r);
  vector<int> totalNines (11, 0);
  for (int i = 1; i < 11; i++)
    totalNines[i] = rightNines[i] - leftNines[i];

  auto changesFromNines = [](vector<int> nines) {
    long long changes = 0;
    for (long long i = 1; i < 11; i++)
      changes += nines[i] * (i + 1);
    return changes;
  };

#if DEBUG
  cout << "\t";
  for (auto x : totalNines)
    cout << x << " ";
  cout << endl;
#endif
  long long ans = r - l - accumulate(totalNines.begin(), totalNines.end(), (long long)0) + changesFromNines(totalNines);

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

