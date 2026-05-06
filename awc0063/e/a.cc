// https://atcoder.jp/contests/awc0063/editorial/19874

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// https://betrue12.hateblo.jp/entry/2020/09/22/194541
struct S {
  int l; // 左端の色
  int r; // 右端の色
  int cnt; // ブロック数
};
using F = int;  // 写像
S op(S a, S b) {
  S n;
  if (a.l == -1 && b.r == -1) {
    n.l = n.r = -1;
  } else if (a.l == -1) {
    n.l = n.r = b.r;
  } else if (b.r == -1) {
    n.l = n.r = a.l;
  } else {
    n.l = a.l;
    n.r = b.r;
  }
  n.cnt = a.cnt + b.cnt;
  if (a.r != -1 && b.l != -1 && a.r == b.l) {
    n.cnt--;
  }
  return n;
}  // 写像
S e() {
  S e;
  e.l = e.r = -1;
  e.cnt = 0;
  return e;
}  // 写像の単位元
F id(){ return -2; }  // 恒等写像
S mapping(F f, S x) {
  if (f == id()) {
    return x;
  } else {
    x.l = x.r = f;
    x.cnt = 1;
  }
  return x;
}  // 写像を要素に適用したものを返す
F composition(F f, F g) {
  if (f == id()) {
    return g;
  } else {
    return f;
  }
}  // 合成写像を返す。gを先に適用してfを後で適用する。

void print_lazy_segtree(int N, lazy_segtree<S, op, e, F, mapping, composition, id> &seg) {
  vector<S> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = seg.get(n); }
  cerr << '[';
  for (int i = 0; i < N; i++) {
    //cerr << '['<< i << ']=';
    cerr << '(' << v[i].l << ' ' << v[i].r << ' ' << v[i].cnt << ')';
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
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  vector<S> ss(N);
  for (int i = 0; i < N; i++) {
    ss.at(i).l = C.at(i);
    ss.at(i).r = C.at(i);
    ss.at(i).cnt = 1;
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(ss); // 配列Aで初期化
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int L, R, X;
      cin >> L >> R >> X;
      L--;
      seg.apply(L, R, X);
    } else {
      int L, R;
      cin >> L >> R;
      L--;
      int ans = seg.prod(L, R).cnt;
      cout << ans << '\n';
    }
  }
  return 0;
}
