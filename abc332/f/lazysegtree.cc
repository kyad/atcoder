#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

using Prob = mint;

#include <atcoder/lazysegtree>
using namespace atcoder;

using S = Prob;
// アフィン変換
using F = struct {
  Prob a;
  Prob b;
};

S op(S a, S b){ (void)a; (void)b; return 0; } // a, b: any
S e(){ return 0; } // any
S mapping(F f, S x){ return f.a * x + f.b; }
F composition(F f, F g){
  F ans;
  ans.a = g.a * f.a;
  ans.b = g.b * f.a + f.b;
  return ans;
}
F id(){
  F ans;
  ans.a = 1;
  ans.b = 0;
  return ans;
}  

int main() {
  int N, M;
  cin >> N >> M;
  vector<S> A(N, 0);
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    A.at(n) = (Prob)(a);
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

  for (int m = 0; m < M; m++) {
    int L, R;
    int x;
    cin >> L >> R >> x;
    L--; R--;
    Prob X = (Prob)x;

    int n = R - L + 1;
    Prob p = (Prob)(1) / n;
    Prob q = (Prob)(1) - p;

    F f;
    f.a = q;
    f.b = p * X;
    seg.apply(L, R + 1, f);
  }

  vector<Prob> E(N);
  for (int i = 0; i < N; i++) {
    E.at(i) = seg.get(i);
  }

  {
    for (int n = 0; n < N; n++) {
      cout << E.at(n) << " \n"[n + 1 == N];
    }
  }

  return 0;
}
