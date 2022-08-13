// https://atcoder.jp/contests/arc140/tasks/arc140_b

#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  multiset<int> st;
  size_t left = 0;
  size_t pos;
  while (left < N && ((pos = S.find("ARC", left)) != string::npos)) {
    int a_count = 0;
    int a = pos - 1;
    while (a >= 0 && S[a] == 'A') {
      a--;
      a_count++;
    }
    int c_count = 0;
    int c = pos + 3;
    while (c < N && S[c] == 'C') {
      c++;
      c_count++;
    }
    st.insert(min(a_count, c_count));
    left = c;
  }
  // Simulation
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (st.empty()) {
      break;
    }
    ans++;
    if (i % 2 == 1) {
      auto it = prev(st.end());
      int now = *it;
      st.erase(it);
      if (now > 0) {
        st.insert(now - 1);
      }
    } else {
      st.erase(st.begin());
    }
  }
  cout << ans << endl;
  return 0;
}
