#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main()
{
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  long long int health = 0;
  while(n--)
  {
    int x;
    cin >> x;
    pq.push(x);
    health += x;
    if (health < 0)
    {
      health -= pq.top();
      pq.pop();
    }
  }
  cout << pq.size() << endl;
  

  return 0;
}
