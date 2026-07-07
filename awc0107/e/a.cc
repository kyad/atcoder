#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間最小値
using S = pair<long long, int>;
using F = long long;
S op(S a, S b){ return std::min(a, b); }
S e(){ return make_pair(4e18, 1e9); } // INF
S mapping(F f, S x){ return make_pair(f+x.first, x.second); }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

void print_lazy_segtree(int N, lazy_segtree<S, op, e, F, mapping, composition, id> &seg) {
  vector<S> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = seg.get(n); }
  cerr << '[';
  for (int i = 0; i < N; i++) {
    //cerr << '['<< i << ']=';
    cerr << v[i].first;
    //cerr << v[i].value;  // 区間和の時
    const int MOD = -1;
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { cerr << '\n'; }
    else { cerr << ' '; }
  }
  cerr << ']' << endl;
}

int main() {
  int T, N, D, Q;
  cin >> T >> N >> D >> Q;

  vector<pair<long long, int>> A(T - D + 1);
  for (int t = 0; t <= T - D; t++) {
    A.at(t) = make_pair(0, t);
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

  vector<int> L(N), R(N);

  for (int i = 0; i < N; i++) {
    cin >> L.at(i) >> R.at(i);
    if (R.at(i) - L.at(i) <= D) {
      seg.apply(max(0, R.at(i) - D), min(T - D, L.at(i)) + 1, 1);
    }
  }

  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, l, r;
      cin >> i >> l >> r;
      i--;
      if (R.at(i) - L.at(i) <= D) {
        seg.apply(max(0, R.at(i) - D), min(T - D, L.at(i)) + 1, -1);
      }
      L.at(i) = l;
      R.at(i) = r;
      if (R.at(i) - L.at(i) <= D) {
        seg.apply(max(0, R.at(i) - D), min(T - D, L.at(i)) + 1, 1);
      }
    } else {
      S opt = seg.all_prod();
      cout << opt.second << ' ' << opt.first << '\n';
    }
  }
  return 0;
}
