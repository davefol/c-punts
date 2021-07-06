#include <iostream>
using namespace std;

void solve()
{
    int x;
    cin >> x;
    // Frobenius number for n = 2
    // 11 * 111 - 11 - 111 = 1099
    if (x > 1099)
    {
        cout << "YES" << endl;
        return;
    }

    // Brute force for all numbers less than 1099
    for (int i=0; i<100; i++)
        for (int j=0; j<10; j++)
        {
            if (i*11 + j*111 == x)
            {
                cout << "YES" << endl;
                return;
            }
        }
    cout << "NO" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       solve(); 
    }
}
