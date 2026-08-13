// https://atcoder.jp/contests/awc0134/editorial/23513

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


int main() {
  int N, Q;
  long long P, D;
  cin >> N >> Q >> P >> D;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  vector<int> U(N, -1);

  // 尺取り法。[l, r)は半開区間とする
  int r = 0;
  long long sum = 0;
  for (int l = 0; l < N; l++) {
    // 条件を満たす最大のrを求める
    while (true) {
      int nr = r + 1;
      if (nr >= N + 1) {
        break;
      }
      // nrが条件を満たしているかチェック
      // 例：
      long long nsum = sum + A[nr - 1];
      if (nsum > P - D) {
        break;
      }
      r = nr;
      // 条件にrを含める
      // 例：
      sum = nsum;
    }

    // この時点で[l, r)は条件を見たす最大の区間
    // 何かする。
    // r=0の場合があるので、r=0の場合は配列のr-1番目にアクセスしないように注意する。
    if (sum == P - D && l < r) {
      assert(U.at(r - 1) == -1);
      U.at(r - 1) = l;
    }

    // lをインクリメントする前の処理
    if (l == r) {
      // このとき、[l, r)は空集合なので、条件からlを除外する処理は不要
      r++;  // 先にrをインクリメントする
    } else {
      // 条件からlを除外する
      sum -= A.at(l);
    }
  }

  binary_indexed_tree<int> C(N);
  binary_indexed_tree<long long> T(N);

  vector<vector<pair<int, int>>> query(N);
  for (int qi = 0; qi < Q; qi++) {
    int L, R;
    cin >> L >> R;
    L--; R--;
    query.at(R).push_back({L, qi});
  }

  vector<int> ans_c(Q);
  vector<long long> ans_t(Q);
  for (int r = 0; r < N; r++) {
    int u = U.at(r);
    if (u >= 0) {
      C.add(u, 1);
      T.add(u, r - u + 1);
    }
    for (auto [l, qi]: query.at(r)) {
      int c = C.sum(l, N);
      long long t = T.sum(l, N);
      ans_c.at(qi) = c;
      ans_t.at(qi) = t;
    }
  }
  for (int qi = 0; qi < Q; qi++) {
    cout << ans_c.at(qi) << ' ' << ans_t.at(qi) << '\n';
  }
  return 0;
}
