#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

template<class T> struct binary_indexed_tree {
  int N;
  vector<T> bit;  // 1-indexed
  binary_indexed_tree() {}
  binary_indexed_tree(int n) : N(n) {
    bit.resize(N + 1, 0);
  }
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
  void add0(int k, T x) {
    add1(k + 1, x);
  }
  // Returns a[1] + a[2] + ... + a[k], O(logN)
  // k: 1-indexed
  T sum1(int k) {
    T ret = 0;
    for (; k > 0; k -= (k & -k)) {
      ret += bit[k];
    }
    return ret;
  }
  // Returns a[0] + a[1] + ... + a[k], O(logN)
  // k: 0-indexed
  T sum0(int k) {
    return sum1(k + 1);
  }
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
  T lower_bound0(T w) {
    return lower_bound1(w) - 1;
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  const int M = 200000;
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  binary_indexed_tree<long long> seg(M);
  binary_indexed_tree<long long> count(M);
  // dp
  vector<mint> dp(N, 0);
  dp[0] = A[0];
  {
    int x = A[0];
    seg.add1(x, x);
    count.add1(x, 1);
  }
  for (int i = 1; i < N; i++) {
    mint iinv = mint(1) / mint(i + 1);
    mint ex1 = (mint(i) * iinv) * (mint(i) * iinv) * dp[i - 1];
    dp[i] += ex1;
    mint ex2 = iinv * iinv * A[i];
    dp[i] += ex2;
    // etc
    int x = A[i];
    long long sum = seg.sum1(M) - seg.sum1(x);
    mint ex3 = iinv * iinv * 2 * mint(sum);
    dp[i] += ex3;
    
    long long num = count.sum1(x);
    mint ex4 = iinv * iinv * 2 * x * mint(num);
    dp[i] += ex4;
    // Update
    seg.add1(x, x);
    count.add1(x, 1);
  }
  for (int n = 0; n < N; n++) {
    cout << dp[n].val() << '\n';
  }
  return 0;
}
