#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
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

const int INF = 1e9+1;

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  set<int> st;
  st.insert(-1);
  st.insert(INF);
  for (int i = 0; i < N; i++) {
    st.insert(H.at(i));
  }
  vector<int> rev;
  for (int h : st) {
    rev.push_back(h);
  }
  int M = rev.size();
  map<int, int> mp;
  for (int j = 0; j < M; j++) {
    mp[rev.at(j)] = j;
  }

  // 1点更新・区間最大値
  auto fx = [](int x1, int x2) -> int { return max(x1, x2); };
  SegTree<int> seg(M, fx, -INF);

  // 初期化 j: 0-indexed
  for (int j = 0; j < M; j++) {
    seg.set(j, 0);
  }
  seg.build(); // 構築

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int h = H.at(i);
    int j = mp[h];
    int left_h = max(-1, h - D);
    int right_h = min(INF, h + D);
    //auto [left_j, left_h2] = *mp.lower_bound(left_h);
    int left_h_mod = *st.lower_bound(left_h);
    //auto [right_j, right_h2] = *prev(mp.upper_bound(right_h));
    int right_h_mod = *prev(st.upper_bound(right_h));
    int left_j = mp[left_h_mod];
    int right_j = mp[right_h_mod];
    int now = seg.query(left_j, right_j + 1) + 1;
    seg.update(j, now);
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
