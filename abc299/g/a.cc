#include <algorithm>
#include <cassert>
#include <iostream>
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

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    A.at(n)--;
  }
  vector<vector<int> > ns(M);
  for (int n = 0; n < N; n++) {
    ns[A[n]].push_back(n);
  }
  set<int> st;  // 未選択の番号(0~M-1)の末尾の(index, 番号)
  for (int m = 0; m < M; m++) {
    st.insert(ns[m].back());
  }
  // 1点更新・区間最小値
  const int INF = M + 1;
  auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
  SegTree<int> rmq(N, fx, INF);
  for (int n = 0; n < N; n++) {
    rmq.set(n, A[n]);
  }
  rmq.build();

  int l = 0;  // 貪欲のindex
  vector<int> B;
  for (int m = 0; m < M; m++) {
    assert(!st.empty());
    int r = *st.begin();
    assert(l <= r);
    int number = rmq.query(l, r + 1);
    B.push_back(number + 1);
    l = *lower_bound(ns[number].begin(), ns[number].end(), l) + 1;
    for (int n : ns[number]) {
      rmq.update(n, INF);
    }
    int remove = ns[number].back();
    assert(st.count(remove) > 0);
    st.erase(remove);
  }
  dumpvec(B);
  return 0;
}
