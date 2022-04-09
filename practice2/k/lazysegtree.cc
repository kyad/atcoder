// https://atcoder.jp/contests/practice2/tasks/practice2_k

#include <iostream>
#include <vector>
#include <atcoder/lazysegtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

struct S {
  mint value;
  int size;
};
struct F {
  mint b;
  mint c;
};
S op(S a, S b) { return { a.value + b.value, a.size + b.size }; }
S e() { return { 0, 0 }; }
S mapping(F f, S x) { return { f.b * x.value + f.c * x.size, x.size }; }
F composition(F f, F g) { return { f.b * g.b, f.b * g.c + f.c }; }
F id() { return { 1, 0 }; }

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<S> v(N);
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    v.at(n) = { a, 1 };
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  for (int q = 0; q < Q; q++) {
    int mode;
    cin >> mode;
    if (mode == 0) {
      int l, r, b, c;
      cin >> l >> r >> b >> c;
      F f = { b, c };
      seg.apply(l, r, f);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l, r).value.val() << endl;
    }
  }
  return 0;
}
