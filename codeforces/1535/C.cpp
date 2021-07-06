#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DEBUG false

void solve()
{
  string s;
  cin >> s;
#if DEBUG
  cout << "\t" << s << endl;
#endif
  int N = s.size();

  // 2x2 table of prefix counts
  // x is 0 or 1
  // p is the parity (0 for even 1 for odd)
  // [1][0] tells us the number of ones at even positions
  vector<int> prefix_count[2][2];

  for (int x = 0; x < 2; x++)
    for (int p = 0; p < 2; p++)
    {
      prefix_count[x][p].assign(N+1, 0);

      for (int i=0; i < N; i++)
        prefix_count[x][p][i+1] = prefix_count[x][p][i] + (i % 2 == p && s[i] - '0' == x);
    }

  // from start to end is there an occurenct of x at an index of p % 2
  // so exists(0, 5, 1, 0) tells us if there is a 1 that is at an index with even parity
  auto exists = [&](int start, int end, int x, int p) -> bool 
  {
    return prefix_count[x][p][end] - prefix_count[x][p][start] > 0;
  };

  auto beautiful = [&](int start, int end) -> bool
  {
    for (int x = 0; x < 2; x++)
      if (exists(start, end, x, 0) && exists(start, end, x, 1))
        return false;
    for (int p=0; p<2; p++)
      if (exists(start, end, 0, p) && exists(start, end, 1, p))
        return false;

    return true;
  };

  int64_t total = 0;

  for (int start = 0; start < N; start++)
  {
    int low = start, high = N;

    while (low < high)
    {
      int mid = low + (high - low + 1) / 2;

      if (beautiful(start, mid))
        low = mid;
      else
        high = mid - 1;
    }
    total += low - start;
#if DEBUG
    cout << "\t" << "low: " << low << ", start: " << start << ", total: " << total << endl;
#endif
  }
  cout << total << endl;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--)
        solve();
    return 0;
}
