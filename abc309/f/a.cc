// https://www.youtube.com/watch?v=uP5u7K6QJVs&t=5591s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <functional>

const int INF = 1e9;

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

// Coordinate compression
// https://github.com/atcoder/live_library/blob/master/cc.cpp
// 圧縮後の値は0からN-1 (Nはsize())
#include <algorithm>
template<typename T=int> struct CC {
  bool initialized;
  vector<T> xs;
  CC() : initialized(false) {}
  void add(T x) { xs.push_back(x); }
  void init() {  // O(Nlog(N))
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    initialized = true;
  }
  int operator()(T x) {  // 圧縮前の値から圧縮後の値を得る。O(logN)
    if (!initialized) { init(); }
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {  // 圧縮後の値から圧縮前の値を得る。O(1)
    if (!initialized) { init(); }
    return xs[i];
  }
  int size() {
    if (!initialized) { init(); }
    return xs.size();
  }
};

int main() {
  int N;
  cin >> N;
  map<int, vector<pair<int, int> > > mp;
  CC cc;
  for (int n = 0; n < N; n++) {
    vector<int> B(3);
    cin >> B[0] >> B[1] >> B[2];
    sort(B.begin(), B.end());
    mp[B[0]].push_back(make_pair(B[1], B[2]));
    cc.add(B[1]);
  }

  // 1点更新・区間最小値
  auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
  SegTree<int> seg(N, fx, INF);

  for (auto [a, bcs] : mp) {
    for (auto [b, c] : bcs) {
      int y = cc(b);
      if (seg.query(0, y) < c) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    for (auto [b, c] : bcs) {
      int y = cc(b);
      int now = seg.get(y);
      seg.update(y, min(c, now));
    }
  }
  cout << "No" << endl;
  return 0;
}
