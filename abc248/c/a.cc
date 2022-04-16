#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N, M, K;
  cin >> N >> M >> K;
  int NM = N * M;
  vector<vector<long long> > dp(N + 1, vector<long long>(NM + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= NM; j++) {
      if (j + 1 <= NM) {
        dp[i][j + 1] += dp[i - 1][j];
        dp[i][j + 1] %= MOD;
      }
      if (j + M + 1 <= NM) {
        dp[i][j + M + 1] += (((long long)MOD) - dp[i - 1][j]);
        dp[i][j + M + 1] %= MOD;
      }
    }
    for (int j = 1; j <= NM; j++) {
      dp[i][j] += dp[i][j - 1];
      dp[i][j] %= MOD;
    }
  }
  long long ans = 0;
  for (int j = 0; j <= K; j++) {
    ans += dp[N][j];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
