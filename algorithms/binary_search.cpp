#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto printv = [&]() {
    for (auto x : v)
      cout << x << " ";
  };

  auto print_uline = [&](int i) {
    for (int j = 0; j < v.size(); j++) {
      if (j == i)
        cout << "\033[4m" << v[j] << "\033[0m" << " ";
      else
        cout << v[j] << " ";
    }
    cout << endl;
  };

  auto bisearch = [&](int target) {
    int ll = 0;
    int rr = v.size() - 1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      if (v[mid] == target)
        return mid;
      if (v[mid] > target) // look left
        rr = mid - 1;
      else // look right
        ll = mid + 1;
    }
    return -1;
  };

  auto search_and_print = [&](int target) {
    cout << "searching for target " << target << endl;
    int index = bisearch(target);
    
    if (index != -1)
      print_uline(index);
    else
      cout << "could not find target " << target;
    cout << endl;
  };

  search_and_print(4);
  search_and_print(7);
  search_and_print(11);
  cout << endl;

  auto bisearch_lower = [&](int target) {
    int ll = 0;
    int rr = v.size() - 1;
    int ans = -1;
    while (ll <= rr) {
      int mid = ll + (rr - ll) / 2;
      if (v[mid] >= target) {
        ans = mid;
        rr = mid - 1;
      } else {
        ll = mid + 1;
      }
    }
    return ans;
  };

  v = vector<int> {2, 4, 6, 8};
  auto search_lower_and_print = [&](int target) {
    cout << "searching for target " << target << endl;
    int index = bisearch_lower(target);
    
    if (index != -1)
      print_uline(index);
    else
      cout << "could not find target " << target;
    cout << endl;
  };

  search_lower_and_print(1);
  search_lower_and_print(3);
  search_lower_and_print(7);
  search_lower_and_print(11);


  return 0;
}
