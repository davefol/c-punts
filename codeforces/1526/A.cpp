#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i=0; i<2*n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i=0; i<n; i++)
        {
            cout << a[i] << " " << a[2*n-i-1] << " ";
        }
        cout << endl;
    }
    return 0;
}
