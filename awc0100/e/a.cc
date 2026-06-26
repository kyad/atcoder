#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}


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

// Coordinate compression
// https://github.com/atcoder/live_library/blob/master/cc.cpp
// 圧縮後の値は0からN-1 (Nはsize())
#include <algorithm>
template<typename T=int> struct CC {
  bool initialized;
  vector<T> xs;
  CC() : initialized(false) {}
  void add(T x) { xs.push_back(x); }
  void init() {  // O(Nlog(N))
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    initialized = true;
  }
  int operator()(T x) {  // 圧縮前の値から圧縮後の値を得る。O(logN)
    if (!initialized) { init(); }
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {  // 圧縮後の値から圧縮前の値を得る。O(1)
    if (!initialized) { init(); }
    return xs[i];
  }
  int size() {
    if (!initialized) { init(); }
    return xs.size();
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  CC cc;
  for (int i = 0; i < N; i++) {
    cc.add(A.at(i));
  }
  cc.init();
  int M = cc.size();
  binary_indexed_tree<int> bit(M);
  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    int z = cc(a);
    bit.add(z, 1);
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    int z = cc(a);
    int sum = bit.sum(z + 1, M);
    B.at(i) = sum;
  }
  dump(B);
  return 0;
}
