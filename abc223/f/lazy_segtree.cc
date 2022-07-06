// https://atcoder.jp/contests/abc223/tasks/abc223_f

#include <algorithm>
#include <iostream>
#include <vector>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

// 区間加算・区間最小値取得
using S = long long;
using F = long long;
const S INF = 8e18;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  string str;
  cin >> str;
  vector<S> v(N + 1, 0);
  for (int n = 0; n < N; n++) {
    v.at(n + 1) = (str[n] == '(' ? 1 : -1);
  }
  vector<S> sum(v);
  for (int n = 0; n < N; n++) {
    sum.at(n + 1) += sum.at(n);
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(sum);
  for (int q = 0; q < Q; q++) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      if (v.at(l) == 1 && v.at(r) == -1) {
        F f = -2;
        seg.apply(l, r, f);
      } else if (v.at(l) == -1 && v.at(r) == 1) {
        F f = 2;
        seg.apply(l, r, f);
      }
      swap(v.at(l), v.at(r));
    } else {
      if (v.at(l) == 1
          && v.at(r) == -1
          && seg.get(l - 1) == seg.get(r)
          && seg.prod(l - 1, r) >= seg.get(r)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
