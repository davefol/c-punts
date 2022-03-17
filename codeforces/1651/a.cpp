#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        uint64_t n;
        cin >> n;
        if (n == 1)
            cout << 1 << endl;
        else
            cout << (1 << n) - 1 << endl;
    }
    return 0;
}
