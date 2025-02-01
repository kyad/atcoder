#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 1e9+10;

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

  // 取得 O(1)
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

// // 更新クエリ O(logN) i: 0-indexed
// seg.update(i, x);
// // 取得クエリ O(logN) [l, r), l, r: 0-indexed
// long long ans = seg.query(l, r);

// 区間更新ならlazysegtreeを使う


int main() {
  int N, W;
  cin >> N >> W;
  vector<vector<int> > ys(W);
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    X.at(i) = x;
    Y.at(i) = y;
    ys.at(x).push_back(y);
  }
  for (int x = 0; x < W; x++) {
    sort(ys.at(x).begin(), ys.at(x).end());
  }

  // mp[y]: 高さy以下に最小で何個あるか
  map<int, int> mp;
  {
    // 1点更新・区間最小値
    auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
    SegTree<int> seg(W, fx, INF);
    // 初期化 i: 0-indexed
    for (int i = 0; i < W; i++) {
      seg.set(i, 0);
    }
    seg.build();  // 構築
    vector<pair<int, int> > yx(N);
    for (int i = 0; i < N; i++) {
      yx.at(i) = make_pair(Y.at(i), X.at(i));
    }
    sort(yx.begin(), yx.end());
    for (auto [y, x] : yx) {
      int prev = seg.get(x);
      seg.update(x, prev + 1);
      mp[y] = seg.query(0, W);
    }
  }

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int T, A;
    cin >> T >> A;
    A--;
    int x = X.at(A);
    int y = Y.at(A);
    // yの下(y含む)に何個あるか
    int c = upper_bound(ys.at(x).begin(), ys.at(x).end(), y) - ys.at(x).begin();
    
    // すべての列につき、高さT以下にc個以上あるか？
    auto it = mp.upper_bound(T);
    int k = prev(it)->second;  // 高さTにおける最小個数
    if (k >= c) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }
  return 0;
}
