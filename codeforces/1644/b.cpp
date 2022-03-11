#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>
#include <deque>

using namespace std;

void print_vector(deque<int> v) {
    for (auto it: v)
        cout << it << " ";
    cout << endl;
}

void solve(int n) {
   // 4 3 2 1
   // 1 4 3 2
   // 2 1 4 3
   // 3 2 1 4
   //
   // 3 2 1
   // 1 3 2
   // 3 1 2
   //
   // 5 4 3 2 1
   // 1 5 4 3 2
   // 2 1 5 4 3
   // 3 2 1 5 4
   // 4 3 2 1 5

    if (n == 3) {
        cout << "3 2 1\n3 1 2\n1 3 2\n";
        return;
    }

    deque<int> permutation (n);
    for (int i = 0; i < n; i++)
        permutation[i] = i + 1;
    reverse(permutation.begin(), permutation.end());
    print_vector(permutation);
    for (int i = 0; i < n - 1; i++) {
        permutation.push_front(permutation.back());
        permutation.pop_back();
        print_vector(permutation);
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
