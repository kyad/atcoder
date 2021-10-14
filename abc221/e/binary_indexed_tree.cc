// https://atcoder.jp/contests/abc221/tasks/abc221_e
// https://algo-logic.info/binary-indexed-tree/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MOD = 998244353;

template<class T> struct binary_indexed_tree {
  int N;
  vector<T> bit;
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
  void add(int k, T x) {
    for (; k <= N; k += (k & -k)) {
      bit[k] += x;
      bit[k] %= MOD;
    }
  }
  // Returns a[1] + a[2] + ... + a[k], O(logN)
  // k: 1-indexed
  T sum(int k) {
    int ret = 0;
    for (; k > 0; k -= (k & -k)) {
      ret += bit[k];
      ret %= MOD;
    }
    return ret;
  }
  // Returns minimum x such that a[1] + a[2] + ... + a[x] >= w, O(logN)
  int lower_bound(T w) {
    if (w <= 0) {
      return 0;
    } else {
      int x = 0;
      int r = 1;
      while (r < N) {
        r = r << 1;
      }
      for (int len = r; len > 0; len = len >> 1) {
        if (x + len < N && bit[x + len] < w) {
          w += MOD;
          w -= bit[x + len];
          w %= MOD;
          x += len;
        }
      }
      return x + 1;
    }
  }
};

// Return 0-order compressed vector whose size is same as A
vector<int> compress(vector<int> A) {
  vector<int> a(A);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  map<int, int> m;
  for (size_t i = 0; i < a.size(); i++) {
    m[a[i]] = i;
  }
  vector<int> ans(A.size());
  for (size_t i = 0; i < A.size(); i++) {
    ans[i] = m[A[i]];
  }
  return ans;
}

// Solve ax = 1 mod m  (m != prime is OK), O(log m)
// Solve ay = b mod m --> y = b * x mod m
long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) {
    u += m;
  }
  return u;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> a = compress(A);
  int n = a.size();
  binary_indexed_tree<long long> bit(n);
  long long ans = 0;
  long long pow2 = 1;
  long long powinv2 = 1;
  long long inv2 = modinv(2, MOD);
  for (int r = 0; r < N; r++) {
    powinv2 *= inv2;
    powinv2 %= MOD;
    // pow2 = 2^r
    // powinv2 = (1/2)^(r+1)
    ans += pow2 * bit.sum(a[r] + 1);
    ans %= MOD;
    bit.add(a[r] + 1, powinv2);
    pow2 *= 2;
    pow2 %= MOD;
  }
  cout << ans << endl;
  return 0;
}
