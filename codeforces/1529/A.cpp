#include <iostream>
using namespace std;

void solve()
{
    int count[101];
    for (auto &c : count)
        c = 0;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        count[x] ++;
    }
    int m = 0;
    for (auto c: count)
    {
        if (c != 0)
        {
            m = c;
            break;
        }
    }
    cout << n - m << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
