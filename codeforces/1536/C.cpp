#include <iostream>
#include <numeric>
#include <map>
#include <utility>

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  int d = 0;
  int k = 0;
  std::map<std::pair<int, int>, int> count;
  std::cin >> s;
  for (auto c : s) {
    if (c == 'D') d++;
    if (c == 'K') k++;
    int _gcd = std::gcd(d, k);
    int first = d / _gcd;
    int second = k / _gcd;
    std::pair<int, int> key {first, second};
    count[key]++;
    std::cout << count[key] << " ";
  }
    std::cout << std::endl;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) solve();
  return 0;
}
