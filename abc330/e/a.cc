// https://atcoder.jp/contests/abc330/editorial/7752

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  // N以上はNとして扱う
  auto mod = [&](int &x) {
    if (x >= N) {
      x = N;
    }
  };

  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    mod(A.at(n));
  }

  // 初期化
  set<int> st;  // Aに含まれない数字の集合
  for (int n = 0; n <= N; n++) {
    st.insert(n);
  }
  vector<int> cnt(N + 1, 0);  // cnt[n]: nの個数
  for (int a : A) {
    mod(a);
    cnt[a]++;
    if (st.contains(a)) {
      st.erase(a);
    }
  }

  // クエリ処理
  for (int q = 0; q < Q; q++) {
    int i, x;
    cin >> i >> x;
    i--; mod(x);
    if (A[i] != x) {
      // 増やす
      if (cnt[x] == 0) {
        assert(st.contains(x));
        st.erase(x);
      }
      cnt[x]++;
      // 減らす
      assert(cnt[A[i]] >= 1);
      if (cnt[A[i]] == 1) {
        st.insert(A[i]);
      }
      cnt[A[i]]--;
      A[i] = x;
    }
    int ans = st.empty() ? 0 : *st.begin();
    cout << ans << '\n';
  }
  return 0;
}
