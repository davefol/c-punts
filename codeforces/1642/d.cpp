#include <iostream>
#include <vector>
#include <map>
#include <utility>

#define DEBUG 0

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (auto &x: a)
        cin >> x;
#if DEBUG
    cout << "original:\n";
    for (auto x : a)
        cout << x << " ";
    cout << endl;
#endif
    map<int, int> counts;
    for (auto x : a)
        if (!counts.count(x))
            counts[x] = 0;
        else
            counts[x] += 1;

    bool impossible = false;
    for (auto x: counts)
        if (x.second % 2 == 0) {
            impossible = true;
            break;
        }

    if (impossible) {
        cout << "-1" << endl;
        return;
    }

    vector<pair<int, int> > ops;
    for (int stop = a.size(); stop > 1; stop--) {
        int max_index = distance(a.begin(), max_element(a.begin(), a.begin() + stop));
        reverse(a.begin(), a.begin() + max_index + 1);
        for (int i = 0; i <= max_index; i++) {
            ops.push_back(make_pair(max_index + i, a[i]));
            ops.push_back(make_pair(max_index + i, a[i]));
        }
        reverse(a.begin(), a.begin() + stop);
        for (int i = 0; i < stop; i++) {
            ops.push_back(make_pair(max_index + i, a[i]));
            ops.push_back(make_pair(max_index + i, a[i]));
        }
    }
#if DEBUG
    cout << "Answer:\n";
#endif
    cout << ops.size() << endl;
    for (auto x : ops) {
        cout << x.first << " " << x.second << endl;
    }
    cout << a.size() / 2 << endl;
    for (int i = 0; i < a.size() / 2; i++) {
        cout << 2 << " ";
    }
    cout << endl;

#if DEBUG
    cout << "sorted:\n";
    for (auto x : a)
        cout << x << " ";
    cout << endl;
#endif

}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
