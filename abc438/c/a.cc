#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  stack<int> st;
  auto check = [&]() -> bool {
    if (st.size() <= 3) {
      return false;
    }
    int a, b, c, d;
    a = st.top(); st.pop();
    b = st.top(); st.pop();
    c = st.top(); st.pop();
    d = st.top(); st.pop();
    if (a == b && b == c && c == d) {
      return true;
    }
    st.push(d);
    st.push(c);
    st.push(b);
    st.push(a);
    return false;
  };
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    st.push(A);
    while (true) {
      bool now = check();
      if (!now) {
        break;
      }
    }
  }
  int ans = st.size();
  cout << ans << '\n';
  return 0;
}
