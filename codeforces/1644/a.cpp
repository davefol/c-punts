#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>

using namespace std;

void solve(string a) {
    set<char> keys;
    for (auto c : a) {
        if (c == 'r' || c == 'b' || c == 'g')
            keys.insert(c);
        if (c == 'R' and !keys.count('r')) {
            cout << "NO\n";
            return;
        }
        if (c == 'B' and !keys.count('b')) {
            cout << "NO\n";
            return;
        }
        if (c == 'G' and !keys.count('g')) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string a;
        cin >> a;
        solve(a);
    }
    return 0;
}
