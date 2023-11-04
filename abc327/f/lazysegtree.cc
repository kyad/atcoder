#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間最大値
using S = int;
using F = int;
const S INF = 1e9;
S op_max(S a, S b){ return std::max(a, b); }
S e_max(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
  const int MX = 200000;
  int N, D, W;
  cin >> N >> D >> W;
  // xs[t]: 時刻tに落ちるりんごの座標達
  vector<vector<int> > xs(MX + 1);
  for (int i = 0; i < N; i++) {
    int T, X;
    cin >> T >> X;
    xs.at(T).push_back(X);
  }
  
  // 初期化
  vector<int> B(MX + 1, 0);
  lazy_segtree<S, op_max, e_max, F, mapping, composition, id> seg_max(B);

  // 補助関数
  auto add = [&](int t, int value) {
    for (int x : xs[t]) {
      int l = x;
      int r = min(x + W, MX + 1);
      seg_max.apply(l, r, value);
    }
  };

  // 初期値
  for (int t = 1; t <= D; t++) {
    add(t, +1);
  }
  int ans = seg_max.all_prod();

  // ずらす
  for (int t = 2; t <= MX - (D - 1); t++) {
    add(t - 1, -1);  // t-1を外す
    add(t + (D - 1), +1);  // t+Dを追加
    int now = seg_max.all_prod();
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
