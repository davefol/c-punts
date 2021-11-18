#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define vp vector<pair<int, int>>
#define vvp vector<vp>

vvp pairings(set<int> available) {

}

int main() {
  auto test_pairings = [&](int n) {
    cout << "N=" << n << endl;
    set<int> avail;
    for (int i = 0; i < n; i++)
      avail.insert(i);
    for (auto & x : avail)
      cout << x << " ";
    cout << endl;
    auto _pairings = pairings(avail);
    for (auto & x : _pairings) {
      for (auto & y : x)
        cout << "(" << y.first << ", " << y.second << ")" << " ";
      cout << endl;
    }
  };

  test_pairings(2);
  test_pairings(4);
  test_pairings(6);

  return 0;


}
