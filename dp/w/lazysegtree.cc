// https://atcoder.jp/contests/dp/tasks/dp_w
// https://kyopro-friends.hatenablog.com/entry/2019/01/12/231106
// https://betrue12.hateblo.jp/entry/2020/09/23/005940

#include <iostream>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

// 区間加算・区間最大値取得の遅延評価セグメント木
using S = long long;
using F = long long;
const S INF = 8e18;
S op(S a, S b) { return max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

#if 0
// lazy_segtree
ostream& operator<<(ostream& os, lazy_segtree<S, op, e, F, mapping, composition, id> seg) {
  const int N = 1;
  int MOD = -1;
  os << '[';
  for (int i = 0; i < N; i++) {
    S s = seg.get(i);
    os << s;
    if (i == N - 1) {
      continue;
    } else if (MOD > 0 && i % MOD == (MOD - 1)) {
      os << '\n';
    } else {
      os << ' ';
    }
  }
  os << ']';
  return os;
}
#endif

int main() {
  int N, M;
  cin >> N >> M;
  // LA[r]: ri==rの時のlとaのpair (1-indexed)
  vector<vector<pair<int, int> > > LA(N + 1);
  for (int m = 0; m < M; m++) {
    int l, r, a;
    cin >> l >> r >> a;
    LA[r].push_back(make_pair(l, a));
  }
  // dp[j]: i文字目まで決めて(in-place)、最後が1なのがj文字目のスコアの最大値
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(N + 1);
  seg.set(0, 0);
  for (int i = 1; i <= N; i++) {
    // dp[i] = max{ dp[j] | 0 <= j < i }
    seg.set(i, seg.prod(0, i));
    // dp[j] += a for l <= j <= i
    for (size_t k = 0; k < LA[i].size(); k++) {
      int l = LA[i][k].first;
      int a = LA[i][k].second;
      seg.apply(l, i + 1, a);
    }
  }
  cout << seg.all_prod() << endl;
  return 0;
}
