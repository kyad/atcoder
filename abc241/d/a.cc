#include <iostream>
#include <set>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  multiset<long long> st1, st2;
  for (int q = 0; q < Q; q++) {
    int c;
    cin >> c;
    if (c == 1) {
      long long x;
      cin >> x;
      st1.insert(-x);
      st2.insert(x);
    } else if (c == 2) {
      long long x, k;
      cin >> x >> k;
      multiset<long long>::iterator it = st1.lower_bound(-x);
      long long ans = -1;
      for (int i = 0; i < k - 1; i++) {
        if (it == st1.end()) {
          break;
        }
        it = next(it);
      }
      if (it != st1.end()) {
        ans = -(*it);
      }
      cout << ans << endl;
    } else {
      long long x, k;
      cin >> x >> k;
      multiset<long long>::iterator it = st2.lower_bound(x);
      long long ans = -1;
      for (int i = 0; i < k - 1; i++) {
        if (it == st2.end()) {
          break;
        }
        it = next(it);
      }
      if (it != st2.end()) {
        ans = (*it);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
