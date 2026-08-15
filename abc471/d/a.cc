#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int Q;
  long long V;
  cin >> Q >> V;
  multiset<long long> ms;
  long long offset = 0;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      long long T, W;
      cin >> T >> W;
      W -= T;
      ms.insert(W);
      offset = T;
    } else if (type == 2) {
      long long T;
      cin >> T;
      offset = T;
      if (ms.empty()) {
        cout << -1 << '\n';
      } else {
        long long mx = *ms.rbegin();
        long long ans = mx + offset;
        if (ans > V) {
          ans = V;
        }
        cout << ans << '\n';
        ms.erase(ms.find(mx));
      }
    }
  }
  return 0;
}
