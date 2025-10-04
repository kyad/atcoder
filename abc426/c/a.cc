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
  int N, Q;
  cin >> N >> Q;
  vector<S> A(N + 1);
  for (int i = 0; i <= N; i++) {
    A.at(i) = i;
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);  // 配列Aで初期化
  int maxi = 0;
  for (int qi = 0; qi < Q; qi++) {
    int X, Y;
    cin >> X >> Y;
    S now = seg.get(X);
    cout << now << '\n';
    seg.apply(X, Y, -now);
    for (int i = maxi + 1; i <= X - 1; i++) {
      seg.set(i, 0);
    }
    maxi = max(maxi, X);
  }
  return 0;
}
