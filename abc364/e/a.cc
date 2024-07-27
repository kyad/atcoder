// https://atcoder.jp/contests/abc364/editorial/10550

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N + 1, 0), B(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  const int INF = 1e9;
  // dp[i][j][k]: iまで見た時に甘さの合計jで食べた料理k個の時のしょっぱさの合計の最小値
  vector<vector<vector<int> > > dp(N + 1, vector<vector<int> >(X + 1, vector<int>(N + 1, INF)));
  dp[0][0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= X; j++) {
      for (int k = 0; k <= N; k++) {
        chmin(dp[i][j][k], dp[i - 1][j][k]);  // iを取らない
        if (j - A[i] >= 0 && k >= 1) {
          chmin(dp[i][j][k], dp[i - 1][j - A[i]][k - 1] + B[i]);  // iを取る
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= X; j++) {
    for (int k = 0; k <= N; k++) {
      if (dp[N][j][k] <= Y) {
        ans = max(ans, k);
      }
    }
  }
  ans++;
  ans = min(N, ans);
  cout << ans << endl;
  return 0;
}
