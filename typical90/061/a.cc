#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int Q;
  cin >> Q;
  deque<int> dq;
  for (int _q = 0; _q < Q; _q++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      dq.push_front(x);
    } else if (t == 2) {
      dq.push_back(x);
    } else {
      cout << dq.at(x - 1) << '\n';
    }
  }
  return 0;
}
