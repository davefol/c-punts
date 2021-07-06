#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;

#define DEBUG false
#define rep(i, n) for (int i = 0; i < int(n); i++)

void solve()
{
  int n;
  cin >> n;
  vector<int> u(n), s(n);
  rep(i, n)
  {
    int x;
    cin >> x;
    x--;
    u[i] = x;
  }
  rep(i, n)
  {
    int x;
    cin >> x;
    s[i] = x;
  }
  vector<vector<int>> us(*max_element(u.begin(), u.end()) + 1);
  rep(i, n) us[u[i]].push_back(s[i]);
  rep(i, us.size()) sort(us[i].begin(), us[i].end(), greater<int>());
  vector<vector<long long>> psum(us.size(), vector<long long>(1, 0));
  rep(i, us.size()) for (int x : us[i]) psum[i].push_back(psum[i].back() + x);
  vector<long long> ans(n);
  rep(i, us.size()) for (int k = 1; k <= us[i].size(); k++)
    ans[k - 1] += psum[i][us[i].size() / k * k];
  rep(i, n)
    cout << ans[i] <<  " ";
  cout << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
}

