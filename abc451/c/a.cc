#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  multiset<int> st;
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int type, h;
    cin >> type >> h;
    if (type == 1) {
      st.insert(h);
    } else {
      while (!st.empty()) {
        if (*st.begin() <= h) {
          st.erase(st.begin());
        } else {
          break;
        }
      }
    }
    int ans = st.size();
    cout << ans << '\n';
  }
  return 0;
}
