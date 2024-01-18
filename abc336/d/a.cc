#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間最小値
using S = long long;
using F = long long;
const S INF = 4e18;
S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
  int N;
  cin >> N;
  vector<S> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  for (int i = 0; i < N; i++) {
    A[i] += i;
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
  int ans = 1;
  for (int i = 0; i < N; i++) {
    int k0 = i + 1;
    int k1 = N - i;
    int kmax = min(k0, k1);
    int l = i - kmax + 1;
    int r = i + kmax;
    assert(0 <= l);
    assert(r <= N);
    int now = seg.prod(l, r);
    now = min(now, kmax);
    ans = max(ans, now);
    seg.apply(0, i + 1, +1);
    seg.apply(i + 1, N, -1);
  }
  cout << ans << endl;
  return 0;
}
