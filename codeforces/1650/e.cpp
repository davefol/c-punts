#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <math.h>
#include <string>
#include <set>
#include <iterator>

# define DEBUG 0

using namespace std;

void printa(vector<int> a) {
    for (auto it : a)
        cout << it << " ";
    cout << endl;
}

int findu(vector<int> exams, int days) {
    // find the largest gap
    vector<int> gaps (exams.size() + 1);
    gaps[0] = exams[0] - 1;
    for (int i = 1; i < exams.size() ; i++) {
        gaps[i] = exams[i] - exams[i-1] - 1; 
    }
    gaps[exams.size()] = days - exams[exams.size() - 1];

    // insert an exam halfway through the largest gap
    int max_gap_i = distance(gaps.begin(), max_element(gaps.begin(), gaps.end()));
    int subans = gaps[max_gap_i] / 2;
    if (!(gaps[max_gap_i] % 2))
        subans--;
    if (max_gap_i == gaps.size() - 1)
        subans = gaps[gaps.size() - 1] - 1;
    int ans = min(subans, *min_element(gaps.begin(), gaps.end() - 1));
    return ans;
}

void solve(int n_exams, int days, vector<int> exams) {
    //for (auto &it: exams)
    //    it--;

#if DEBUG
    cout << "input:\n";
    printa(exams);
#endif
    // determine the exam with the shortest break
    vector<int> breaks (n_exams);
    breaks[0] = exams[0] - 1;
    for (int i = 1; i < n_exams; i++)
        breaks[i] = exams[i] - exams[i-1] - 1;

    // try removing the exams that make up the shortest break
    int min_break_i = distance(breaks.begin(), min_element(breaks.begin(), breaks.end()));
    vector<int> exams2 = exams;
    exams.erase(exams.begin() + min_break_i);
    if (min_break_i > 0)
        exams2.erase(exams.begin() + min_break_i - 1);
    else
        exams2.erase(exams.begin() + min_break_i);

    cout << max(findu(exams, days), findu(exams2, days)) << endl;
#if DEBUG
    cout << "remove shortest:\n";
    printa(exams);
#endif

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a (n);
        for (auto &it: a)
            cin >> it;
        solve(n, d, a);
    }
    return 0;
}
