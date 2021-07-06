#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<long long int> v;
  cout << n - 1 << endl;
  while(n--)
  {
    long long int x;
    cin >> x;
    v.push_back(x);
  }
  int min_idx = min_element(v.begin(), v.end()) - v.begin();
  long long int min_val = *min_element(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
  {
    if (i != min_idx)
      cout << min_idx + 1 << " " << i + 1 << " " << min_val << " " << abs(i - min_idx) + min_val << endl;
  }
}

int main()
{
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}
