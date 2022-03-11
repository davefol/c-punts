#include <iostream>
#include <vector>
#include <map>

#define DEBUG 1

using namespace std;

void reverse_pref(
        vector<int> &ar,
        vector<pair<int, int>> &ans,
        vector<int> &lens,
        int &mdf,
        int len
) {
    for (int i = 0; i < len; i++)
        ans.emplace_back(len + mdf + i, ar[i]);
    
#if DEBUG
    cout << "ans: ";
    for (auto it : ans)
        cout << "(" << it.first << ", " << it.second << ")" << " ";
    cout << endl;
#endif

    if (len != 0)
        lens.push_back(len * 2);

    mdf += len * 2;
#if DEBUG
    cout << "mdf: " << mdf << endl;
#endif

    reverse(ar.begin(), ar.begin() + len);
}

void move_to_front(
        vector<int> &ar,
        vector<pair<int, int>> &ans,
        vector<int> &lens,
        int &mdf,
        int id
) {
    reverse_pref(ar, ans, lens, mdf, id);
    reverse_pref(ar, ans, lens, mdf, id + 1);
}

void solve(int n, vector<int> ar) {
    // store counts of elements 
    // in order to check parity
    map<int, int> cnt;
    for (auto it : ar)
        cnt[it]++;

    // if any of the numbers
    // has an odd parity
    // then we cant make tandem
    // repeats since a tandem
    // repeat will double
    // each number
    // hint look at 2k from problem statement
    for (auto it : cnt) {
        if (it.second % 2) {
            cout << "-1" << endl;
            return;
        }
    }

    vector<int> br = ar;
    // sorts the array descending
    // br.rbegin() returns a reverse iterator
    // pointing to the last element in br
    sort(br.rbegin(), br.rend());

    vector<pair<int, int>> ans;
    vector<int> lens;
    
    // request capacity to be ...
    ans.reserve(n * n * 2);
    lens.reserve(n * 2);

    // no fucking clue what this is ???
    int mdf = 0;

#if DEBUG
    cout << "ar:\n";
    for (auto it : ar)
        cout << it << " ";
    cout << endl;

    cout << "sort(br.rbegin(), br.rend()):\n";
    for (auto it : br)
        cout << it << " ";
    cout << endl;
#endif

    for (int i = 0; i < n; i++) {
        // we have the reverse sorted array
        // and the original array
        // and we will iterate through the reverse sorted array
        // and look for that element between i and end (what we havent sorted)
        // then move it to the front of the array
        // while we do this, we keep track of the moves required to sort.

        // ar =     1 [3] 1 2 2 3
        // br =     [3] 3 2 2 1 1
        // ar* =    [3] 1 1 2 2 3 
        // ----------------------
        // ar =     3 1 1 2 2 [3]
        // br =     3 [3] 2 2 1 1
        // ar* =    [3] 3 1 1 2 2
        // ----------------------
        // ar =     3 3 1 1 [2] 2
        // br =     3 3 [2] 2 1 1
        // ar* =    [2] 3 3 1 1 2
        // ----------------------
        // ar =     2 3 3 1 1 [2]
        // br =     3 3 2 [2] 1 1
        // ar* =    [2] 2 3 3 1 1
        // ----------------------
        // ar =     2 2 3 3 [1] 1
        // br =     3 3 2 2 [1] 1
        // ar* =    [1] 2 2 3 3 1
        // ----------------------
        // ar =     1 2 2 3 3 [1]
        // br =     3 3 2 2 1 [1]
        // ar* =    [1] 1 2 2 3 3
        
        int fnd = (int)(find(ar.begin() + i, ar.end(), br[i]) - ar.begin());
        move_to_front(ar, ans, lens, mdf, fnd);
#if DEBUG
        cout << "\tafter move to front\n";
        for (auto it : ar)
            cout << it << " ";
        cout << endl;
#endif
    }
}

int main() {
    int t; // number of test cases
    cin >> t;
    while(t--) { // for each test case
        int n; // size of sequence
        cin >> n;
        vector<int> ar (n); // allocate space for sequence
        for (auto &it : ar)
            cin >> it; // read in sequence
        solve(n, ar);
    }
}
