#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<long long> > dp(N + 1, vector<long long>(M + 2, 0));
  for (int j = 1; j <= M; j++) {
    dp[1][j] = 1;
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (K == 0) {
        dp[i][0] += dp[i - 1][j];
        dp[i][0] %= MOD;
        dp[i][M + 1] += MOD;
        dp[i][M + 1] -= dp[i - 1][j];
      } else {
        if (j - K >= 1) {
          dp[i][0] += dp[i - 1][j];
          dp[i][0] %= MOD;
          dp[i][j - K + 1] += MOD;
          dp[i][j - K + 1] -= dp[i - 1][j];
          dp[i][j - K + 1] %= MOD;
        }
        if (j + K <= M) {
          dp[i][j + K] += dp[i - 1][j];
          dp[i][j + K] %= MOD;
          dp[i][M + 1] += MOD;
          dp[i][M + 1] -= dp[i - 1][j];
          dp[i][M + 1] %= MOD;
        }
      }
    }
    for (int j = 1; j <= M + 1; j++) {
      dp[i][j] += dp[i][j - 1];
      dp[i][j] %= MOD;
    }
  }
  long long ans = 0;
  for (int j = 1; j <= M; j++) {
    ans += dp[N][j];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
