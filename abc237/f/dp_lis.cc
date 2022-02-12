// https://atcoder.jp/contests/abc237/tasks/abc237_f

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N, M;
  cin >> N >> M;
  // dp[i][a1][a2][a3]: i個目まで見た時に、LISのDP配列がa1, a2, a3であるような個数。
  // aiには0, 1, ... , M-1を入れることにする。ai == MはINFが入っていることを表す。
  vector<vector<vector<vector<long long> > > > dp(N + 1, vector<vector<vector<long long> > >(M + 1, vector<vector<long long> > (M + 1, vector<long long> (M + 1, 0))));
  dp[0][M][M][M] = 1;
  // 配るDP
  for (int i = 0; i < N; i++) {
    // 全部の状態を見る
    for (int a1 = 0; a1 <= M; a1++) {
      for (int a2 = 0; a2 <= M; a2++) {
        for (int a3 = 0; a3 <= M; a3++) {
          // xは、i個目に入れる数字
          for (int x = 0; x < M; x++) {
            if (x < a1) {
              dp[i + 1][x][a2][a3] += dp[i][a1][a2][a3];
              dp[i + 1][x][a2][a3] %= MOD;
            } else if (x == a1) {
              dp[i + 1][a1][a2][a3] += dp[i][a1][a2][a3];
              dp[i + 1][a1][a2][a3] %= MOD;
            } else if (x < a2) {
              dp[i + 1][a1][x][a3] += dp[i][a1][a2][a3];
              dp[i + 1][a1][x][a3] %= MOD;
            } else if (x == a2) {
              dp[i + 1][a1][a2][a3] += dp[i][a1][a2][a3];
              dp[i + 1][a1][a2][a3] %= MOD;
            } else if (x < a3) {
              dp[i + 1][a1][a2][x] += dp[i][a1][a2][a3];
              dp[i + 1][a1][a2][x] %= MOD;
            } else if (x == a3) {
              dp[i + 1][a1][a2][a3] += dp[i][a1][a2][a3];
              dp[i + 1][a1][a2][a3] %= MOD;
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int a1 = 0; a1 < M; a1++) {
    for (int a2 = 0; a2 < M; a2++) {
      for (int a3 = 0; a3 < M; a3++) {
        ans += dp[N][a1][a2][a3];
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
