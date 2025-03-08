#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  stack<int> st;
  for (int i = 0; i < 100; i++) {
    st.push(0);
  }
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      st.push(x);
    } else {
      int ans = st.top();
      st.pop();
      cout << ans << endl;
    }
  }
  return 0;
}
