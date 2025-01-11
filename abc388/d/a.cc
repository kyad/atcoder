#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

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
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  vector<long long> D(N, 0);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(D);
  
  for (int i = 0; i < N; i++) {
    int r = N - 1 - i;  // 残り人数
    A.at(i) += seg.get(i);  // もらう
    long long ss = min(A.at(i), (long long)r);  // 渡す数
    int s = (int)ss;
    A.at(i) -= s;
    assert(i + 1 + s <= N);
    seg.apply(i + 1, i + 1 + s, 1);
  }

  dump(A);
  return 0;
}
