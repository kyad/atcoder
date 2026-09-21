#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> struct binary_indexed_tree {
  int N;
  vector<T> bit;  // 1-indexed
  binary_indexed_tree() {}
  binary_indexed_tree(int n) : N(n) { bit.resize(N + 1, 0); }
  void resize(int n) { N = n; bit.resize(N + 1, 0); }
  // Add x to a[k], 1-indexed, O(logN)
  void add1(int k, T x) {
    for (; k <= N; k += (k & -k)) {
      bit[k] += x;
    }
  }
  // Add x to a[k], 0-indexed, O(logN)
  void add0(int k, T x) { add1(k + 1, x); }
  // Returns sum for [0, k], 1-indexed, O(logN)
  T sum1_closed(int k) const {
    T ret = 0;
    for (; k > 0; k -= (k & -k)) {
      ret += bit[k];
    }
    return ret;
  }
  // Returns sum for [l, r], 1-indexed, O(logN)
  T sum1_closed(int l, int r) const { if (l == 1) { return sum1_closed(r); } else { return sum1_closed(r) - sum1_closed(l - 1); } }
  // Returns sum for [l, r), 1-indexed, O(logN)
  T sum1_open(int l, int r) const { if (l == r) { return 0; } else { return sum1_closed(l, r - 1); } }
  // Returns sum for [0, k], 0-indexed, O(logN)
  T sum0_closed(int k) const { return sum1_closed(k + 1); }
  // Returns sum for [0, k), 0-indexed, O(logN). 半開区間の場合は[0, k)が空集合(k==0)の場合にも使え、0を返す。
  T sum0_open(int k) const { if (k == 0) { return 0; } return sum1_closed(k); }
  // Returns sum for [l, r], 0-indexed, O(logN)
  T sum0_closed(int l, int r) const { return sum1_closed(l + 1, r + 1); }
  // Returns sum for [l, r), 0-indexed, O(logN)
  T sum0_open(int l, int r) const { if (l == r) { return 0; } return sum1_closed(l + 1, r + 1 - 1); }
  // Returns a[k]
  T get1(int k) const { return (k == 1) ? sum1_closed(k) : (sum1_closed(k) - sum1_closed(k - 1)); }
  T get0(int k) const { return get1(k + 1); }
  // Update, 1-indexed, O(logN)
  void update1(int k, T x) { T old = get1(k); add1(k, -old); add1(k, x); }
  // Update, 0-indexed, O(logN)
  void update0(int k, T x) { add1(k + 1, x); }
  // Returns minimum x such that a[1] + a[2] + ... + a[x] >= w, O(logN)
  // return: 1-indexed (0: not found)
  T lower_bound1(T w) {
    if (w <= 0) {
      return 0;
    } else {
      T x = 0;
      int r = 1;
      while (r < N) {
        r = r << 1;
      }
      for (int len = r; len > 0; len = len >> 1) {
        if (x + len < N && bit[x + len] < w) {
          w -= bit[x + len];
          x += len;
        }
      }
      return x + 1;
    }
  }
  // return: 0-indexed (-1: not found)
  T lower_bound0(T w) { return lower_bound1(w) - 1; }
  // atcoder::fenwick_treeのインタフェースに似せる
  void add(int p, T x) { add0(p, x); }
  T sum(int l, int r) { return sum0_open(l, r); }
  T sum(int k) { return sum0_open(k); }
  T get(int k) const { return get0(k); }
  void update(int k, T x) { update0(k, x); }
};

template<class X> ostream& operator<<(ostream& os, const binary_indexed_tree<X> &bit) {
  int N = bit.N;
  vector<X> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = bit.get0(n); }
  os << '[';
  for (int i = 0; i < N; i++) {
    //os << '['<< i << "]=";
    os << v[i];
    const int MOD = -1;
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { os << '\n'; }
    else { os << ' '; }
  }
  os << ']';
  return os;
}

// BITの区間加算・1点取得はimos法の値をbitで管理する。
// binary_indexed_tree<long long> bit(N + 1);
// [l, r]にxを加算：add(l, x), add(r + 1, x)
// 1点iの取得：sum(0, i)
// cf. https://atcoder.jp/contests/abc253/tasks/abc253_f

// A[i]にiの多項式を掛けた値の和を計算したい場合は、
// iについて展開して、i^k*A[i]を要素に持つbinary indexed treeを考える

// Example
// binary_indexed_tree<int> bit(N);
// bit.add(i, x);
// int sum = bit.sum(l, r);


#include <functional>

// 抽象化したセグメント木
template<class X> struct SegTree {
  using FX = function<X(X, X)>;
  int n;  // n_以上の最小の2べき
  FX fx;  // 二項演算 X x X -> X
  X ex;  // 単位元
  vector<X> dat;  // dat[0]~dat[2*n-2]に値が入る

  void init(int n_, FX fx_, X ex_) {
    fx = fx_;
    ex = ex_;
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
    dat.resize(2 * n - 1, ex_);
  }
  SegTree(): n(), fx(), ex() {}
  SegTree(int n_, FX fx_, X ex_) { init(n_, fx_, ex_); }

  // 初期化 O(N) i: 0-indexed
  void set(int i, X x) { dat[i + n - 1] = x; }  // dat[n-1]~dat[2n-2]に値が入る
  void set1(int i, X x) { set(i - 1, x); }  // 1-indexed
  void build() {  // O(logN)
    for (int k = n - 2; k >= 0; k--) {
      dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }

  // 取得 O(1)
  X get(int i) { return dat[i + n - 1]; }  // 0-indexed
  X get1(int i) { return get(i - 1); }  // 1-indexed

  // 更新クエリ O(logN) i: 0-indexed
  void update(int i, X x) {
    i += (n - 1);
    dat[i] = x;
    while (i > 0) {  // 最下段から上がる
      i = (i - 1) / 2;  // parent
      dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  void update1(int i, X x) { update(i - 1, x); }  // 1-indexed

  // 取得クエリ O(logN) [a, b), a, b: 0-indexed
  X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  X query1(int a, int b) { return query(a - 1, b - 1); }  // 1-indexed
  X query_sub(int a, int b, int k, int l, int r) {
    // k: 現在見ているノードの位置 [l, r): dat[k]が表している区間
    if (r <= a || b <= l) {  // 範囲外
      return ex;
    } else if (a <= l && r <= b) {  // 範囲内
      return dat[k];
    } else {  // 一部区間が被る時
      X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
};

template<class X> ostream& operator<<(ostream& os, const SegTree<X> &segtree) {
  int depth = 0;
  int temp = segtree.n;
  while (temp > 0) {
    temp /= 2;
    depth++;
  }
#if 0
  int d0 = 0;  // Show all tree
#else
  int d0 = depth - 1;  // Show bottom
#endif
  for (int d = d0; d < depth; d++) {
    int left = (1<<d) - 1;
    int right = (1<<(d+1)) - 1;
    for (int i = left; i < right; i++) {
      //os << "["<< (i - left) << "]=";
      X val = segtree.dat[i];
      os << val;
      //if (abs(val) == 4e18) { if (val < 0) {os << '-'; } os << "inf"; } else { os << val; }
      os << (i == right - 1 ? '\n' : ' ');
    }
  }
  return os;
}

// 1点更新・区間最小値
// auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
// SegTree<int> seg(N, fx, INF);
// auto fx = [](long long x1, long long x2) -> long long { return min(x1, x2); };
// SegTree<long long> seg(N, fx, INF);

// // 初期化 i: 0-indexed
// for (int i = 0; i < N; i++) {
//   seg.set(i, A.at(i));
// }
// seg.build();  // 構築

// // 更新クエリ O(logN) i: 0-indexed
// seg.update(i, x);
// // 取得クエリ O(logN) [l, r), l, r: 0-indexed
// long long ans = seg.query(l, r);

// 区間更新ならlazysegtreeを使う

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  vector<int> W(M);
  for (int j = 0; j < M; j++) {
    cin >> W.at(j);
  }
  int w = *max_element(W.begin(), W.end());
  
  binary_indexed_tree<long long> bit(N);
  for (int i = 0; i < N; i++) {
    bit.add(i, H.at(i));
  }

  // 1点更新・区間最大値
  auto fx = [](long long x1, long long x2) -> long long { return max(x1, x2); };
  const long long INF = 4e18;
  SegTree<long long> seg(N, fx, -INF);
  for (int i = 0; i < N; i++) {
    seg.set(i, H.at(i));
  }
  seg.build();  // 構築

  long long ans = 0;
  for (int l = 0; l <= N - w; l++) {
    long long left = bit.sum(0, l);
    long long middle = seg.query(l, l + w) * w;
    long long right = bit.sum(l + w, N);
    long long now = left + middle + right;
    ans = max(ans, now);
  }

  cout << ans << '\n';
  return 0;
}
