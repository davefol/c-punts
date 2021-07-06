#include <iostream>
#include <vector>
using namespace std;

#define DEBUG false

void solve()
{
  int n;
  cin >> n;
  vector<int> v;
  // number of ones to the left
  // of the index
  vector<long long int> psum (n, 0);
  while(n--)
  {
    char x;
    cin >> x;
    if (x == '.')
      v.push_back(0); 
    else
      v.push_back(1); 
  }
  if (v[0])
    psum[0] = 1;
  for (int i=1; i<v.size(); i++)
  {
    psum[i] = psum[i-1];
    if (v[i])
      psum[i]++;
  }

#if DEBUG
  cout << "\t";
  for (auto k : v)
    cout << k << " ";
  cout << endl;
  cout << "\t";
  for (auto k : psum)
    cout << k << " ";
  cout << endl;
#endif

  auto left = [&](int i) -> int
  {
    return psum[i];
  };
  auto right = [&](int i) -> int
  {
    return psum[v.size()-1] - psum[i];
  };

  long long int ans=0;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == 0)
    {
#if DEBUG
      cout << "\t\t" << "i, l, r" << endl;
      cout << "\t\t" << i << " " << left(i) << " " << right(i) << endl;
#endif
      if (left(i) < right(i))
        ans += left(i);
      else
        ans += right(i);
    }
  }
  cout << ans << endl;



}

int main()
{
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}
