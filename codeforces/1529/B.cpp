#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve()
{
    vector<int> v;
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    if (v[0] > 0)
    {
        cout << "1" << endl;
        return;
    }
    int minDiff = pow(10,9);
    int ans = 1;
    for (int i=0; i<v.size() - 1; i++)
    {
        if (v[i + 1] > 0)
        {
            if (minDiff >= v[i+1])
                ans += 1;
            break;
        }
        minDiff = min(minDiff, v[i+1] - v[i]);
        ans += 1;
    }
    ans = max(0, ans);
    cout << ans << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

}
