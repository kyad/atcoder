// https://atcoder.jp/contests/dp/tasks/dp_m

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 1000000007;
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  // dp[i][j]: i人目までにj個取る場合の数
  vector<vector<long long> > dp(N + 1, vector<long long>(K + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    // imos method
    for (int j = 0; j <= K; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      if (j + A[i] + 1 <= K) {
        dp[i + 1][j + A[i] + 1] += (MOD - dp[i][j]);
        dp[i + 1][j + A[i] + 1] %= MOD;
      }
    }
    for (int j = 0; j < K; j++) {
      dp[i + 1][j + 1] += dp[i + 1][j];
      dp[i + 1][j + 1] %= MOD;
    }
  }
  cout << dp[N][K] << endl;
  return 0;
}
