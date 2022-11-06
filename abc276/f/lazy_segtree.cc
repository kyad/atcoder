// https://atcoder.jp/contests/abc276/tasks/abc276_f

#include <cassert>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace atcoder;
using mint = modint998244353;

// atcoder::lazy_segtree
// https://atcoder.github.io/ac-library/document_ja/lazysegtree.html
// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
// https://betrue12.hateblo.jp/entry/2020/09/23/005940

// 区間加算、区間和
struct S {
    long long value;
    int size;  // 区間幅
};
using F = long long;
S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
// vector<S> v(n, {0, 1});  // 区間幅1で初期化する
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

// Debug print
void print_segtree(lazy_segtree<S, op, e, F, mapping, composition, id> &seg, size_t N) {
  int MOD = -1;
  cout << '[';
  for (size_t i = 0; i < N; i++) {
#if 1
    cout << seg.get(i).value;
#else
    cout << seg.get(i);
#endif
    if (i == N - 1) {
      continue;
    } else if (MOD > 0 && (int)i % MOD == (MOD - 1)) {
      cout << '\n';
    } else {
      cout << ' ';
    }
  }
  cout << ']' << endl;
}

ostream& operator<<(ostream& os, lazy_segtree<S, op, e, F, mapping, composition, id> seg) {
  const int N = 1;  // Change me
  int MOD = -1;
  os << '[';
  for (int i = 0; i < N; i++) {
    S s = seg.get(i);
#if 1
    os << s.value;
#else
    os << s;
#endif
    if (i == N - 1) {
      continue;
    } else if (MOD > 0 && i % MOD == (MOD - 1)) {
      os << '\n';
    } else {
      os << ' ';
    }
  }
  os << ']';
  return os;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  const int M = 200000;
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
#if 1
  vector<S> v(M + 1, {0, 1});  // 区間幅1で初期化する
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  lazy_segtree<S, op, e, F, mapping, composition, id> count(v);
#else
  auto fx = [](long long x1, long long x2) -> long long { return x1 + x2; };
  SegTree<long long> seg(M, fx, 0);
  SegTree<long long> count(M, fx, 0);
  binary_indexed_tree<long long> seg(M);
  binary_indexed_tree<long long> count(M);
#endif
  // dp
  vector<mint> dp(N, 0);
  dp[0] = A[0];
  {
    int x = A[0];
#if 1
    seg.apply(x, x + 1, x);
    count.apply(x, x + 1, 1);
#else
    seg.add1(x, x);
    count.add1(x, 1);
#endif
  }
  for (int i = 1; i < N; i++) {
    mint iinv = mint(1) / mint(i + 1);
    mint ex1 = (mint(i) * iinv) * (mint(i) * iinv) * dp[i - 1];
    dp[i] += ex1;
    mint ex2 = iinv * iinv * A[i];
    dp[i] += ex2;
    // etc
    int x = A[i];
#if 1
    long long sum = seg.prod(x, M + 1).value;
#else
    long long sum = seg.query1(x, M + 1);
    long long sum = seg.sum1(M) - seg.sum1(x);
#endif
    mint ex3 = iinv * iinv * 2 * mint(sum);
    dp[i] += ex3;
    
#if 1
    long long num = count.prod(1, x).value;
#else
    long long num = count.query1(1, x);
    long long num = count.sum1(x);
#endif
    mint ex4 = iinv * iinv * 2 * x * mint(num);
    dp[i] += ex4;
    // Update
#if 1
    seg.apply(x, x + 1, x);
    count.apply(x, x + 1, 1);
#else
    seg.add1(x, x);
    count.add1(x, 1);
#endif
  }
  for (int n = 0; n < N; n++) {
    cout << dp[n].val() << '\n';
  }
  return 0;
}
