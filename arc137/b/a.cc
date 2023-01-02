#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

using S = int;
using F = int;

const S INF = 1e9;

S op_min(S a, S b){ return std::min(a, b); }
S e_min(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

S op_max(S a, S b){ return std::max(a, b); }
S e_max(){ return -INF; }

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    if (A[n] == 0) {
      B[n] = B[n - 1] + 1;
    } else {
      B[n] = B[n - 1] - 1;
    }
  }
  lazy_segtree<S, op_min, e_min, F, mapping, composition, id> seg_min(B);
  lazy_segtree<S, op_max, e_max, F, mapping, composition, id> seg_max(B);
  int mx = -INF;
  int mn = INF;
  for (int i = 0; i <= N; i++) {
    mn = min(mn, seg_min.prod(i, N + 1));
    mx = max(mx, seg_max.prod(i, N + 1));
    if (i != N) {
      int delta = (A[i + 1] == 0 ? -1 : 1);
      seg_min.apply(i + 1, N, delta);
      seg_max.apply(i + 1, N, delta);
    }
  }
  int ans = mx - mn + 1;
  cout << ans << endl;
  return 0;
}
