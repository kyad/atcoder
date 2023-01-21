#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <functional>

// 抽象化したセグメント木
template<class X> struct SegTree {
  using FX = function<X(X, X)>;
  int n;  // n_以上の最小の2べき
  FX fx;  // 二項演算 X x X -> X
  X ex;  // 単位元
  vector<X> dat;  // dat[0]~dat[2*n-2]に値が入る

  void init(int n_, FX fx_, X ex_) {
    fx = fx_;
    ex = ex_;
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
    dat.resize(2 * n - 1, ex_);
  }
  SegTree(): n(), fx(), ex() {}
  SegTree(int n_, FX fx_, X ex_) { init(n_, fx_, ex_); }

  // 初期化 O(N) i: 0-indexed
  void set(int i, X x) { dat[i + n - 1] = x; }  // dat[n-1]~dat[2n-2]に値が入る
  void set1(int i, X x) { set(i - 1, x); }  // 1-indexed
  void build() {  // O(logN)
    for (int k = n - 2; k >= 0; k--) {
      dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }

  // 取得 O(N)
  X get(int i) { return dat[i + n - 1]; }  // 0-indexed
  X get1(int i) { return get(i - 1); }  // 1-indexed

  // 更新クエリ O(logN) i: 0-indexed
  void update(int i, X x) {
    i += (n - 1);
    dat[i] = x;
    while (i > 0) {  // 最下段から上がる
      i = (i - 1) / 2;  // parent
      dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  void update1(int i, X x) { update(i - 1, x); }  // 1-indexed

  // 取得クエリ O(logN) [a, b), a, b: 0-indexed
  X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  X query1(int a, int b) { return query(a - 1, b - 1); }  // 1-indexed
  X query_sub(int a, int b, int k, int l, int r) {
    // k: 現在見ているノードの位置 [l, r): dat[k]が表している区間
    if (r <= a || b <= l) {  // 範囲外
      return ex;
    } else if (a <= l && r <= b) {  // 範囲内
      return dat[k];
    } else {  // 一部区間が被る時
      X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
};

template<class X> ostream& operator<<(ostream& os, const SegTree<X> &segtree) {
  int depth = 0;
  int temp = segtree.n;
  while (temp > 0) {
    temp /= 2;
    depth++;
  }
#if 0
  int d0 = 0;  // Show all tree
#else
  int d0 = depth - 1;  // Show bottom
#endif
  for (int d = d0; d < depth; d++) {
    int left = (1<<d) - 1;
    int right = (1<<(d+1)) - 1;
    for (int i = left; i < right; i++) {
      //os << "["<< (i - left) << "]=";
      X val = segtree.dat[i];
      os << val;
      //if (abs(val) == 4e18) { if (val < 0) {os << '-'; } os << "inf"; } else { os << val; }
      os << (i == right - 1 ? '\n' : ' ');
    }
  }
  return os;
}

// 1点更新・区間最小値
auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
// SegTree<int> seg(n, fx, INF);

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

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> A(N - 1, 0);
  vector<binary_indexed_tree<int> > count(26, binary_indexed_tree<int>(N));
  for (int n = 0; n < N - 1; n++) {
    if (S[n] <= S[n + 1]) {
      A[n] = 1;
    } else {
      A[n] = 0;
    }
  }
  for (int n = 0; n < N; n++) {
    count[S[n] - 'a'].add0(n, 1);
  }
  int INF = 1e9 + 1;
  SegTree<int> seg(N - 1, fx, INF);
  for (int n = 0; n < N - 1; n++) {
    seg.set(n, A[n]);
  }
  seg.build();
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      count[S[x] - 'a'].add0(x, -1);
      S[x] = c;
      count[S[x] - 'a'].add0(x, +1);
      if (x - 1 >= 0) {
        if (S[x - 1] <= S[x]) {
          seg.update(x - 1, 1);
        } else {
          seg.update(x - 1, 0);
        }
      }
      if (x < N - 1) {
        if (S[x] <= S[x + 1]) {
          seg.update(x, 1);
        } else {
          seg.update(x, 0);
        }
      }
    } else {
      int l, r;
      cin >> l >> r;
      l--; r--;
      if (l == r) {
        cout << "Yes" << endl;
        continue;
      }
      int mn = seg.query(l, r);
      bool ans = mn == 1;
      for (int i = S[l] - 'a' + 1; i < S[r] - 'a'; i++) {
        if (count[i].sum0(l, r) != count[i].sum0(0, N - 1)) {
          ans = false;
        }
      }
      cout << (ans ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
