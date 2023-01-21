// https://atcoder.jp/contests/abc285/tasks/abc285_f

#include <cassert>
#include <iostream>
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
  // Returns a[0] + a[1] + ... + a[k], O(logN)
  // k: 0-indexed
  T sum0(int k) {
    return sum1(k + 1);
  }
  // Returns a[0] + a[1] + ... + a[k - 1], O(logN)
  T sum0_semi(int k) {
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

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  binary_indexed_tree<int> cmp(N - 1);
  vector<binary_indexed_tree<int> > count(26, binary_indexed_tree<int>(N));
  for (int n = 0; n < N - 1; n++) {
    if (S[n] > S[n + 1]) {
      cmp.add0(n, 1);
    }
  }
  for (int n = 0; n < N; n++) {
    count[S[n] - 'a'].add0(n, 1);
  }
  int Q;
  cin >> Q;

  auto add = [&](int i, int x) {
    count[S[i] - 'a'].add0(i, x);
    if (i >= 1 && S[i - 1] > S[i]) {
      cmp.add0(i - 1, x);
    }
    if (i < N - 1 && S[i] > S[i + 1]) {
      cmp.add0(i, x);
    }
  };

  for (int q = 0; q < Q; q++) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      add(x, -1);
      S[x] = c;
      add(x, +1);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      bool ans = true;
      if (cmp.sum0_open(l, r - 1) != 0) {
        ans = false;
      }
      for (int i = S[l] - 'a' + 1; i < S[r - 1] - 'a'; i++) {
        if (count[i].sum0_open(l, r) != count[i].sum0_open(0, N)) {
          ans = false;
        }
      }
      cout << (ans ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
