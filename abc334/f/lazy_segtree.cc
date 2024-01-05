#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間最小値
using S = double;
using F = double;
const S INF = 4e18;
S op(S a, S b){ return std::min(a, b); }
S elem(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

/**
 * 距離の2乗を返す
 */
template<typename T> T dist2(T x0, T y0, T x1, T y1) {
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

template<typename T> T dist(T x0, T y0, T x1, T y1) {
  return sqrt(dist2(x0, y0, x1, y1));
}

int main() {
  int N, K;
  cin >> N >> K;
  double SX, SY;
  cin >> SX >> SY;
  vector<double> X(N + 1, 0), Y(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  // e[i] = dist(santa -> i)
  vector<double> e(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    e[i] = dist(SX, SY, X[i], Y[i]);
  }
  // d[i] = dist(i -> i+1) (i = 1, ..., N - 1)
  vector<double> d(N + 1, 0);
  for (int i = 1; i <= N - 1; i++) {
    d[i] = dist(X[i], Y[i], X[i + 1], Y[i + 1]);
  }

  vector<double> zeros(N + 2, 0);
  lazy_segtree<S, op, elem, F, mapping, composition, id> seg(zeros);
  // dp[i]: iに行って戻る時の最小値
  vector<double> dp(N + 1, 0);
  auto myprod = [&](int l, int r) -> double {
    if (l == r) {
      return 0;
    } else {
      return seg.prod(l, r);
    }
  };
  for (int i = 0; i <= N; i++) {
    dp[i] = myprod(max(i - K, 0), i) + e[i];
    seg.apply(max(i - K + 1, 0), i, d[i]);
    if (i <= N - 1) {
      seg.apply(i, i + 1, dp[i] + e.at(i + 1));
    }
  }
  double ans = dp[N];
  cout << setprecision(15) << ans << endl;
  return 0;
}
