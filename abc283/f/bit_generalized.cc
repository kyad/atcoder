// https://atcoder.jp/contests/abc283/tasks/abc283_f

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 一般化したbinary indexed tree
template<class T> struct binary_indexed_tree {
  using FX = function<T(T, T)>;
  int N;
  FX fx;  // 2項演算
  const T ex;  // 単位元
  vector<T> bit;  // 1-indexed
  binary_indexed_tree() {}
  binary_indexed_tree(int n, FX fx_, T ex_) : N(n), fx(fx_), ex(ex_) {
    bit.resize(N + 1, ex);
  }
  void resize(int n, FX fx_, T ex_) {
    N = n;
    bit.resize(N + 1, ex);
  }
  // Add x to a[k], O(logN)
  // k: 1-indexed
  void add1(int k, T x) {
    for (; k <= N; k += (k & -k)) {
      bit[k] = fx(bit[k], x);
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
    T ret = ex;
    for (; k > 0; k -= (k & -k)) {
      ret = fx(ret, bit[k]);
    }
    return ret;
  }
  // Returns a[0] + a[1] + ... + a[k], O(logN)
  // k: 0-indexed
  T sum0(int k) {
    return sum1(k + 1);
  }
  // 区間和の時、Returns minimum x such that a[1] + a[2] + ... + a[x] >= w, O(logN)
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

// 区間和 (未テスト)
// auto fx = [](long long x1, long long x2) -> long long { return x1 + x2; };
// binary_indexed_tree<long long> bit(n, fx, 0);

// 区間最大値
// const int INF = 1e9+2;
// auto fx = [](int x1, int x2) -> int { return max(x1, x2); };
// binary_indexed_tree<int> bit(n, fx, -INF);

// 区間最小値 (未テスト)
// const int INF = 1e9+2;
// auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
// binary_indexed_tree<int> bit(n, fx, INF);


// 区間最大値
const int INF = 4e5+2;
auto fx = [](int x1, int x2) -> int { return max(x1, x2); };


int main() {
  int N;
  cin >> N;
  vector<int> P(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  vector<int> D(N, INF);
  for (int ri = 0; ri < 2; ri++) {  // iを反転するか
    for (int rp = 0; rp < 2; rp++) {  // Pを反転するか
      binary_indexed_tree<int> bit(N, fx, -INF);
      for (int i = 0; i < N; i++) {
        int x = P[i] + i;
        D[i] = min(D[i], x - bit.sum0(P[i]));
        bit.add0(P[i], x);
      }
      for (int n = 0; n < N; n++) {
        P[n] = N - 1 - P[n];
      }
    }
    reverse(P.begin(), P.end());
    reverse(D.begin(), D.end());
  }
  for (int i = 0; i < N; i++) {
    cout << D[i] << ' ';
  }
  cout << endl;
  return 0;
}
