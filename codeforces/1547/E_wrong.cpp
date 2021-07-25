#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;

#define DEBUG false

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> pos (k);
  vector<int> temp (k);
  for (auto & x : pos) {
    int y;
    cin >> y;
    y--;
    x = y;
  }
  for (auto & x : temp)
    cin >> x;

  map <int, int> contributors;

  auto contributor = [&](int cell) {
    if (contributors.count(cell))
      return contributors[cell];
    vector<int> possible_temps;
    for (int i = 0; i < k; i++) {
      possible_temps.push_back(temp[i] + abs(pos[i] - cell));
    } 
    int ac = min_element(possible_temps.begin(), possible_temps.end()) - possible_temps.begin();
    contributors[cell] = ac;
    return ac;
  };

  vector<int> ans (n);

  for (int i = 0; i < k; i++) {
    // i is the index for the air conditioner
    // do a binary search for the right bound
    int ll = pos[i];
    int rr = n;
    int right_bound = - 1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      int contr = contributor(mid);
#if DEBUG 
      cout << "\t\t" << mid << " " << contr << endl;
#endif
      if (contr == i) {
        // it is within the bound
        // check to the right
        right_bound = mid;
        ll = mid + 1;
      } else {
        // otherwise look to the left
        rr = mid - 1;
      }
    }

    ll = 0;
    rr = pos[i];
    int left_bound = -1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      int contr = contributor(mid);
      if (contr == i) {
        // within bound
        // save and search for better
        // answer on the left side
        left_bound = mid;
        rr = mid - 1;
      } else {
        ll = mid + 1;
      }
    }
#if DEBUG
    cout << "\t" << i << " " << left_bound << " " << right_bound << endl;
#endif

    if (left_bound != -1 && right_bound != -1) {
      for (int j = left_bound; j < right_bound + 1; j++) {
#if DEBUG
        cout << "\t" << j << endl;
#endif
        if (j != n) {
          ans[j] = abs(pos[i] - j) + temp[i];
        }
      }
    } else if (left_bound != -1 && right_bound == -1) {
      ans[left_bound] = abs(pos[i] - left_bound) + temp[i];
    } else if (left_bound == -1 && right_bound != - 1) {
      ans[right_bound] = abs(pos[i] - right_bound) + temp[i];
    }
  }

  for (auto & x : ans)
    cout << x << " ";
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}

