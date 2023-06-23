#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {}

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      //return root(parent[x]);  // O(logN)
      return parent[x] = root(parent[x]);  // O(alpha(N))
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    }
    if (_size[x] < _size[y]) {
      swap(x, y);  // Union by size
    }
    parent[y] = x;
    _size[x] += _size[y];
    _num_unions--;
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }

  int num_unions() {  // unionの数(ひとまとまりになっているグループの数)を返す
    return _num_unions;
  }
};

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

/// Return sgn(x) (odd: -1, even: 1)
template<typename T> T sgn(T x) { return (x % 2 == 0) ? 1 : -1; }

int main() {
  int N;
  cin >> N;
  int Q;
  cin >> Q;
  UnionFind uf(N + 1);
  binary_indexed_tree<long long> bit(N);
  for (int qi = 0; qi < Q; qi++) {
    int type;
    int X, Y, V;
    cin >> type >> X >> Y >> V;
    if (type == 0) {
      const int W = V * sgn(X + 1);
      assert(Y == X + 1);
      uf.unite(X, Y);
      bit.add1(X + 1, -bit.get1(X + 1));
      bit.add1(X + 1, W);
    } else if (type == 1) {
      if (X == Y) {
        cout << V << '\n';
        continue;
      }
      if (!uf.issame(X, Y)) {
        cout << "Ambiguous" << '\n';
        continue;
      }
      long long ans = V * sgn(X);
      if (Y > X) {
        ans += bit.sum1_open(X + 1, Y + 1);
      } else {
        ans -= bit.sum1_open(Y + 1, X + 1);
      }
      ans *= sgn(Y);
      cout << ans << '\n';
    } else {
      assert(false);
    }
  }
  return 0;
}
