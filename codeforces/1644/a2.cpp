#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>
#include <utility>

using namespace std;

void solve(string s) {
    vector<pair<char, char>> tests {
        make_pair('r', 'R'),
        make_pair('b', 'B'),
        make_pair('g', 'G')
    };
    for (auto it : tests) {
        if (find(s.begin(), s.end(), it.first) > find(s.begin(), s.end(), it.second)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
