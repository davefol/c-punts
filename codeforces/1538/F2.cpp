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

  auto nthDigit = [](int num, int digit) {
    return num / (int)pow(10, digit - 1) % 10;
  };

  auto nDigits = [](int num) {
    return (int)floor(log10(num) + 1);
  };

  auto changes = [&](int r, int l, int digit) {
    return (int)(r/pow(10, digit)) - (int)(l/pow(10, digit));
  };

  long long ans = r - l;

  for (int i = 1; i < nDigits(r) + 1; i++)
  {
    ans += changes(r, l, i);
  }

  cout << ans << endl;

}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

