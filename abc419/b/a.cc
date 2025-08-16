#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  multiset<int> st;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      st.insert(x);
    } else {
      int ans = *st.begin();
      cout << ans << '\n';
      st.erase(st.begin());
    }
  }
  return 0;
}
