#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 距離の2乗を返す
 */
template<typename T> T dist2(T x0, T y0, T x1, T y1) {
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

template<class T> void chmax(T& a, const T b) { a = max(a, b); }
template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  const long long INF = 4e18;
  vector<long long> d(1<<N, 0);  // 集合bit内の距離の最大値。空・要素が1つだけは0
  for (int bit = 0; bit < (1<<N); bit++) {
    for (int i = 0; i < N; i++) {
      if (!(bit>>i&1)) {
        continue;
      }
      for (int j = i + 1; j < N; j++) {
        if (!(bit>>j&1)) {
          continue;
        }
        long long dist = dist2(X[i], Y[i], X[j], Y[j]);
        chmax(d[bit], dist);
      }
    }
  }
  // BIT dp
  // dp[bit][cnt]: 状態bitのうちグループがcntの時の最大値の最小値
  // 0 <= bit < 1<<N, 1<=cnt<=K
  vector<vector<long long> > dp(1<<N, vector<long long>(K + 1, INF));
  for (int bit = 0; bit < 1<<N; bit++) {
    // cnt==1の時    
    dp[bit][1] = d[bit];
    for (int cnt = 2; cnt <= K; cnt++) {
      if (__builtin_popcount(bit) < cnt) {
        continue;
      }
      for (int b = bit; b >= 0; b--) {
        b &= bit;  // 部分集合の部分集合の列挙 O(3^N)
        // bはbitの部分集合
        int s = bit & (~b);  // s = bit \ b
        long long now = max(dp[b][cnt - 1], d[s]);
        chmin(dp[bit][cnt], now);
      }
    }
  }
  long long ans = dp[(1<<N) - 1][K];
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
