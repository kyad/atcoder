// https://atcoder.jp/contests/abc284/tasks/abc284_f
// https://atcoder.github.io/ac-library/document_ja/string.html
// https://niuez.hatenablog.com/entry/2019/12/16/203739

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/string>
using namespace atcoder;

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

/** Suffix array同士の任意区間のLCPを計算する */
struct LCPArray {
  string S;
  int N;
  SegTree<int> seg;
  vector<int> sa;
  vector<int> sa_inv;
  vector<int> la;
  /**
   * コンストラクタ。任意区間のLCPを計算するためにSegTreeを構築する。
   * 計算量はO(|S|)。
   *
   * \param[in] S 文字列
   */
  LCPArray(const string &_S): S(_S) {
    N = S.size();
    sa = suffix_array(S);  // O(N);
    sa_inv.resize(N);
    for (int n = 0; n < N; n++) {
      sa_inv.at(sa.at(n)) = n;
    }
    la = lcp_array(S, sa);  // O(N);
    // 1点更新・区間最小値
    auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
    const int INF = 1e9+2;
    seg.init(N - 1, fx, INF);
    for (int n = 0; n < N - 1; n++) {
      seg.set(n, la.at(n));
    }
    seg.build();  // O(logN)
  }
  /**
   * [sa[x]=i, sa[y]=j)のLCP (Longest Common Prefix)の長さ、
   * つまり、S[i, N)とS[j, N)の最長共通接頭辞の長さを返す。
   * 計算量はO(log|S|)。
   *
   * \param[in] i 文字列Sにおけるindex (0-indexed)
   * \param[in] j 文字列Sにおけるindex (0-indexed)
   * \return int LCPの長さ
   */
  int get(int i, int j) {
    if (i == j) {
      return N - i;
    }
    int x = sa_inv.at(i);
    int y = sa_inv.at(j);
    if (x > y) {
      swap(x, y);
    }
    return seg.query(x, y);  // O(logN)
  }
};

int main() {
  int N;
  cin >> N;
  string T;
  cin >> T;
  string u = T.substr(0, N);
  string v = T.substr(N, N * 2);
  string ru(u);
  reverse(ru.begin(), ru.end());
  string rv(v);
  reverse(rv.begin(), rv.end());
  string a = u + rv;
  string b = ru + v;
  // LCP array
  LCPArray la(a);
  LCPArray lb(b);
  for (int i = 0; i < N; i++) {
    if (i > 0 && la.get(0, 2 * N - i) != i) {
      continue;
    }
    int j = N - i;
    if (lb.get(0, 2 * N - j) != j) {
      continue;
    }
    string S = a.substr(0, i) + b.substr(0, j);
    cout << S << endl;
    cout << i << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
