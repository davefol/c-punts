#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5};

  auto print_index = [&](int index) {
    for (int i = 0; i < v.size(); i++) {
      if (index == i)
        cout << "\033[4m" << v[i] << "\033[0m" << " ";
      else
        cout << v[i] << " ";
    }
  };

  int lower_4 = lower_bound(v.begin(), v.end(), 4) - v.begin();

  cout << "lower_bound(4):" << endl;
  print_index(lower_4);
  cout << endl;

  int upper_4 = upper_bound(v.begin(), v.end(), 4) - v.begin();
  cout << "upper_bound(4):" << endl;
  print_index(upper_4);
  cout << endl;

  int upper_7 = upper_bound(v.begin(), v.end(), 7) - v.begin();
  cout << "upper_bound(7):" << endl;
  print_index(upper_7);
  cout << endl;
  cout << upper_7 << endl;
  return 0;
}
