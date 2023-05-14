#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

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
  int N, K;
  cin >> N >> K;
  K--;  // 0-indexed
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  set<int> st;
  for (int a : A) {
    st.insert(a);
  }
  binary_indexed_tree<int> bit(N + 1);
  for (int n = 1; n <= N; n++) {
    bit.add1(n, 1);
  }
  // (深さi, そこのA[i])を返す
  auto g = [&](auto g, int i, int K) -> pair<int, int> {
    // 終了条件
    if (i == N - 1) {
      return make_pair(i, A[N - 1]);
    }
    int sum = bit.sum1_open(1, A[i]);
    if (K < sum) {
      set<int>::iterator it = st.begin();
      for (int k = 0; k < K; k++) {
        it++;
      }
      return make_pair(i, *it);
    }
    assert(K >= sum);
    K -= sum;
    int L = N - i;
    int D = (L - 1) * (L - 2) / 2 + N;
    if (K < D) {
      st.erase(A[i]);
      bit.add1(A[i], -1);
      return g(g, i + 1, K);
    }
    K -= D;
    assert(K >= 0);
    set<int>::iterator it = st.find(A[i]);
    it++;
    for (int k = 0; k < K; k++) {
      it++;
    }
    return make_pair(i, *it);
  };
  pair<int, int> p = g(g, 0, K);
  int depth = p.first;
  int a = p.second;
  vector<int>::iterator left = find(A.begin(), A.end(), A[depth]);
  vector<int>::iterator right = find(A.begin(), A.end(), a);
  right++;
  reverse(left, right);
  dumpvec(A);
  return 0;
}
