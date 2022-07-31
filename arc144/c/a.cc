// https://atcoder.jp/contests/arc144/tasks/arc144_c

#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  const int INF = 300001;
  int N, K;
  cin >> N >> K;
  if (N < 2 * K) {
    cout << -1 << endl;
    return 0;
  }
  set<int> st;
  for (int i = 1; i <= N; i++) {
    st.insert(i);
  }
  vector<int> ans(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    int mn = i - K;
    int mx = i + K;
    if (i < N - K + 1 && mx >= N - K + 1) {  // mxを置ける最後のチャンスの場合は、mxを置く
      ans[i] = mx;
      st.erase(mx);
      continue;
    }
    int left = *st.begin();
    if (mn < left && left < mx) {
      left = INF;
    }
    int right = INF;
    set<int>::iterator it = st.lower_bound(mx);
    if (it != st.end()) {
      right = *it;
    }
    int now = min(left, right);
    assert(now != INF);
    ans[i] = now;
    st.erase(now);
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << (i == N ? '\n' : ' ');
  }
  return 0;
}
