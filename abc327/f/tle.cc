#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/segtree>
using namespace atcoder;

const int INF = 1e9;
int fx(int x1, int x2) { return max(x1, x2); };
int e() { return -INF; };

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
  
  segtree<int, fx, e> seg(MX + 1);
  // 補助関数
  auto add = [&](int t, int value) {
    for (int x : xs[t]) {
      for (int y = x; y <= x + W - 1; y++) {
        if (y > MX) {
          continue;
        }
        int prev = seg.get(y);
        seg.set(y, prev + value);
      }
    }
  };
  // 初期化
  for (int x = 0; x <= MX; x++) {
    seg.set(x, 0);
  }
  for (int t = 1; t <= D; t++) {
    add(t, +1);
  }
  int ans = seg.prod(1, MX + 1);
  // ずらす
  for (int t = 2; t <= MX - (D - 1); t++) {
    add(t - 1, -1);  // t-1を外す
    add(t + (D - 1), +1);  // t+Dを追加
    int now = seg.prod(0, MX + 1);
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
