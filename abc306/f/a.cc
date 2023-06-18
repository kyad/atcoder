#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

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
  // Returns a[l] + a[l + 1] + ... + a[r], O(logN)
  T sum1(int l, int r) {
    if (l == 1) {
      return sum1(r);
    } else {
      return sum1(r) - sum1(l - 1);
    }
  }
  T sum1_open(int l, int r) {
    if (l == r) {
      return 0;
    } else {
      return sum1(l, r - 1);
    }
  }
  // Returns a[0] + a[1] + ... + a[k], O(logN)
  // k: 0-indexed
  T sum0(int k) {
    return sum1(k + 1);
  }
  // Returns a[0] + a[1] + ... + a[k - 1], O(logN)
  // 半開区間の場合は[0, k)が空集合(k==0)の場合にも使え、0を返す。
  T sum0_open(int k) {
    if (k == 0) {
      return 0;
    }
    return sum1(k);
  }
  // Returns a[l] + a[l + 1] + ... + a[r], O(logN)
  T sum0(int l, int r) {
    return sum1(l + 1, r + 1);
  }
  // Returns a[l] + a[l + 1] + ... + a[r - 1], O(logN)
  // 半開区間の場合は[l, r)が空集合(l==r)の場合にも使え、0を返す。
  T sum0_open(int l, int r) {
    if (l == r) {
      return 0;
    }
    return sum1(l + 1, r + 1 - 1);
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

// BITの区間加算・1点取得はimos法の値をbitで管理する。
// binary_indexed_tree<long long> bit(N + 1);
// [l, r]にxを加算：add(l, x), add(r + 1, x)
// 1点iの取得：sum(0, i)
// cf. https://atcoder.jp/contests/abc253/tasks/abc253_f

// A[i]にiの多項式を掛けた値の和を計算したい場合は、
// iについて展開して、i^k*A[i]を要素に持つbinary indexed treeを考える

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > A(N, vector<int>(M));
  vector<int> B;
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      cin >> A.at(n).at(m);
      B.push_back(A.at(n).at(m));
    }
  }
  assert((int)B.size() == N * M);
  sort(B.begin(), B.end());
  map<int, int> mp;
  for (int i = 0; i < N * M; i++) {
    mp[B.at(i)] = i;
  }
  binary_indexed_tree<int> bit(N * M);
  // N - 1
  for (int m = 0; m < M; m++) {
    int i = mp[A[N - 1][m]];
    bit.add0(i, 1);
  }
  long long ans = 0;
  for (int n = N - 2; n >= 0; n--) {
    long long now = 0;
    vector<int> is(M);
    for (int m = 0; m < M; m++) {
      is[m] = mp[A[n][m]];
    }
    for (int k = 0; k < (int)is.size(); k++) {
      const int i = is.at(k);
      now += bit.sum0(i);
      now += (N - 1 - n) * (k + 1);
    }
    for (int i : is) {
      bit.add0(i, 1);
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
