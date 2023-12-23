#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<class T> struct binary_indexed_tree {
  int N;
  vector<T> bit;  // 1-indexed
  binary_indexed_tree() {}
  binary_indexed_tree(int n) : N(n) { bit.resize(N + 1, 0); }
  void resize(int n) {
    N = n;
    bit.resize(N + 1, 0);
  }
  // Add x to a[k], O(logN)
  // k: 1-indexed
  void add1(int k, T x) {
    for (; k <= N; k += (k & -k)) {
      bit[k] += x;
    }
  }
  // Add x to a[k], O(logN)
  // k: 0-indexed
  void add0(int k, T x) { add1(k + 1, x); }
  // Returns a[1] + a[2] + ... + a[k], O(logN)
  // k: 1-indexed
  T sum1(int k) const {
    T ret = 0;
    for (; k > 0; k -= (k & -k)) {
      ret += bit[k];
    }
    return ret;
  }
  // Returns a[l] + a[l + 1] + ... + a[r], O(logN)
  T sum1(int l, int r) const {
    if (l == 1) {
      return sum1(r);
    } else {
      return sum1(r) - sum1(l - 1);
    }
  }
  T sum1_open(int l, int r) const {
    if (l == r) {
      return 0;
    } else {
      return sum1(l, r - 1);
    }
  }
  // Returns a[0] + a[1] + ... + a[k], O(logN)
  // k: 0-indexed
  T sum0(int k) const { return sum1(k + 1); }
  // Returns a[0] + a[1] + ... + a[k - 1], O(logN)
  // 半開区間の場合は[0, k)が空集合(k==0)の場合にも使え、0を返す。
  T sum0_open(int k) const {
    if (k == 0) {
      return 0;
    }
    return sum1(k);
  }
  // Returns a[l] + a[l + 1] + ... + a[r], O(logN)
  T sum0(int l, int r) const { return sum1(l + 1, r + 1); }
  // Returns a[l] + a[l + 1] + ... + a[r - 1], O(logN)
  // 半開区間の場合は[l, r)が空集合(l==r)の場合にも使え、0を返す。
  T sum0_open(int l, int r) const {
    if (l == r) {
      return 0;
    }
    return sum1(l + 1, r + 1 - 1);
  }
  // Returns a[k]
  T get1(int k) const { return (k == 1) ? sum1(k) : (sum1(k) - sum1(k - 1)); }
  T get0(int k) const { return get1(k + 1); }
  // Update, O(logN)  // Not verified
  // k: 1-indexed
  void update1(int k, T x) {
    T old = get1(k);
    add1(k, -old);
    add1(k, x);
  }
  // Update, O(logN)  // Not verified
  // k: 0-indexed
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
};

template<class X> ostream& operator<<(ostream& os, const binary_indexed_tree<X> &bit) {
  int N = bit.N;
  vector<X> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = bit.get0(n); }
  os << '[';
  for (int i = 0; i < N; i++) {
    //os << '['<< i << ']=';
    os << v[i];
    const int MOD = -1;
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { os << '\n'; }
    else { os << ' '; }
  }
  os << ']';
  return os;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> B(N, 0);
  for (int k = 0; k < K; k++) {
    int a;
    cin >> a;
    a--;
    B.at(a) = 1;
  }
  for (int i = 0; i < N - 1; i++) {
    B.at(i + 1) += B.at(i);
    B.at(i + 1) %= 2;
  }

  binary_indexed_tree<int> bit(N);
  for (int i = 0; i < N; i++) {
    if (B.at(i) == 1) {
      bit.add0(i, 1);
    }
  }

  const int INF = 1e9;
  long long ans = INF;
  int b = 2 * N - K;
  if (b % 2 == 1) { // 奇数
    for (int i = 0; i < N; i++) {
      long long now = bit.sum0_open(0, i) + (N - i) - bit.sum0_open(i, N);
      ans = min(ans, now);
    }
  } else {  // 偶数
    ans = bit.sum0_open(N);
  }
  cout << ans << endl;
  return 0;
}
