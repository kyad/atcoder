#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間最小値
using S = int;
using F = int;
const S INF = 1e9;
S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

void print_lazy_segtree(int N, lazy_segtree<S, op, e, F, mapping, composition, id> &seg) {
  vector<S> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = seg.get(n); }
  cerr << '[';
  for (int i = 0; i < N; i++) {
    //cerr << '['<< i << ']=';
    cerr << v[i];
    //cerr << v[i].value;  // 区間和の時
    const int MOD = -1;
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { cerr << '\n'; }
    else { cerr << ' '; }
  }
  cerr << ']' << endl;
}

int main() {
  int N;
  cin >> N;
  const int MX = 5e5;
  vector<int> A(MX + 1, 0);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
  
  for (int i = 0; i < N; i++) {
    int L, R;
    cin >> L >> R;
    int l;
    {  // l
      int left = 0;  // NG
      int right = MX + 1;  // OK
      auto check = [&](int k) -> bool {
        if (k == 0) return false;
        return (k + seg.get(k) >= L);
      };
      while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid)) {
          right = mid;
        } else {
          left = mid;
        }
      }
      l = right;  // OK: right
    }
    int r;
    {  // r
      int left = 0;  // OK
      int right = MX + 1;  // NG
      auto check = [&](int k) -> bool {
        if (k == 0) return true;
        return (k + seg.get(k) <= R);
      };
      while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid)) {
          left = mid;
        } else {
          right = mid;
        }
      }
      r = left;  // OK: left
    }
    seg.apply(l, r + 1, 1);
  }
  vector<int> dp(MX + 1, 0);
  for (int i = 1; i <= MX; i++) {
    dp.at(i) = i + seg.get(i);
  }
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int X;
    cin >> X;
    int ans = dp.at(X);
    cout << ans << '\n';
  }
  return 0;
}
