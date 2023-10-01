#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

typedef struct {
  int mx0;
  int mx1;
  int l0;
  int l1;
  int r0;
  int r1;
  int sz;
} S;

S op(S a, S b) {
  S ans;
  ans.mx0 = max(max(a.mx0, b.mx0), a.r0 + b.l0);
  ans.mx1 = max(max(a.mx1, b.mx1), a.r1 + b.l1);
  // l
  if (a.l0 == a.sz) {
    ans.l0 = a.l0 + b.l0;
  } else {
    ans.l0 = a.l0;
  }
  if (a.l1 == a.sz) {
    ans.l1 = a.l1 + b.l1;
  } else {
    ans.l1 = a.l1;
  }
  // r
  if (b.r0 == b.sz) {
    ans.r0 = b.r0 + a.r0;
  } else {
    ans.r0 = b.r0;
  }
  if (b.r1 == b.sz) {
    ans.r1 = b.r1 + a.r1;
  } else {
    ans.r1 = b.r1;
  }
  // sz
  ans.sz = a.sz + b.sz;
  return ans;
}

S e() {
  S ans;
  ans.mx0 = 0;
  ans.mx1 = 0;
  ans.l0 = 0;
  ans.l1 = 0;
  ans.r0 = 0;
  ans.r1 = 0;
  ans.sz = 0;
  return ans;
}

using F = int;

S mapping(F f, S x) {
  if (f == 1) {
    swap(x.mx0, x.mx1);
    swap(x.l0, x.l1);
    swap(x.r0, x.r1);
  }
  return x;
}

F composition(F f, F g){
  return (f + g) % 2;
}
F id(){ return 0; }

int main() {
  int N, Q;
  cin >> N >> Q;
  string str;
  cin >> str;
  vector<S> A(N);
  for (int n = 0; n < N; n++) {
    int value = str[n] - '0';
    if (value == 0) {
      A[n].mx0 = 1;
      A[n].mx1 = 0;
      A[n].l0 = 1;
      A[n].l1 = 0;
      A[n].r0 = 1;
      A[n].r1 = 0;
      A[n].sz = 1;
    } else {
      A[n].mx0 = 0;
      A[n].mx1 = 1;
      A[n].l0 = 0;
      A[n].l1 = 1;
      A[n].r0 = 0;
      A[n].r1 = 1;
      A[n].sz = 1;
    }
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
  for (int qi = 0; qi < Q; qi++) {
    int C, L, R;
    cin >> C >> L >> R;
    L--;
    if (C == 1) {
      seg.apply(L, R, 1);
    } else {
      S prod = seg.prod(L, R);
      int ans = prod.mx1;
      cout << ans << '\n';
    }
  }
  return 0;
}
