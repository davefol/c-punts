#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve(int n, vector<int> ar) {
    sort(ar.begin(), ar.end());
    int sum_blue = ar[0];
    int sum_red = ar[n-1];
    int blue_index = 0;
    int red_index = n-1;
    int blue_count = 1;
    int red_count = 1;
    for (int i = 1; i < n; i++) {
        if (sum_blue >=  sum_red) {
            red_index--;
            sum_red += ar[red_index];
            red_count++;
        } else {
            blue_index++;
            sum_blue += ar[blue_index];
            blue_count++;
        }
        if (blue_count > red_count && sum_red > sum_blue) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ar (n);
        for (auto &it : ar)
            cin >> it;
        solve(n, ar);
    }
    return 0;
}
