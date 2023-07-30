#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);
  vector<int> A_mx(N, -1);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  set<int> st;
  for (int n = 0; n < N; n++) {
    st.insert(n);
  }
  long long ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (A.at(i) != 1) {
      continue;
    }
    int mx = 0;
    int now = 0;
    int idx_mx = i;
    vector<int> removes;
    for (set<int>::iterator it = st.find(i); it != st.end(); it++) {
      int idx = *it;
      if (A.at(idx) != now + 1) {
        break;
      }
      removes.push_back(idx);
      mx = max(mx, idx);
      idx_mx = max(idx_mx, idx);
      now++;
    }
    if ((idx_mx + 1 < N) && (A_mx[idx_mx + 1] >= 0)) {
      mx = max(mx, A_mx[idx_mx + 1]);
    }
    ans += (long long)(mx - i + 1);
    for (int idx : removes) {
      st.erase(st.find(idx));
    }
    A_mx[i] = mx;
  }
  cout << ans << endl;
  return 0;
}
