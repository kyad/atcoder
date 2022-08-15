// https://atcoder.jp/contests/agc058/tasks/agc058_b

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N;
  cin >> N;
  vector<int> P(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> P.at(n);
  }
  vector<int> L(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (P[j] > P[i]) {
        L[i] = j;
        break;
      }
    }
  }
  vector<int> R(N + 1, N + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (P[j] > P[i]) {
        R[i] = j;
        break;
      }
    }
  }
  // 区間[li, ri)の個数で、Li<li<ri<=Ri(またはP[i]を取らない場合は空の区間)の個数を数える。
  // dp[i][j]: P[1]からP[i]までを使う区間の個数で、ri==jの個数
  // 1<=i<=N, 1<=j<=N+1
  vector<vector<long long> > dp(N + 1, vector<long long>(N + 2, 0));
  dp[0][1] = 1;
  for (int i = 1; i <= N; i++) {
    // P[i]を取らない場合の遷移
    // dp[i][j] <-- dp[i - 1][j]
    for (int j = 1; j <= N + 1; j++) {
      dp[i][j] = dp[i - 1][j];
    }
    // P[i]を取る場合の遷移
    // dp[i][k] <-- dp[i - 1][j], j=Li+1,..,Ri-1, k=j+1,..,Ri
    vector<long long> imos(N + 3, 0);
    for (int j = L[i] + 1; j <= R[i] - 1; j++) {
      imos[j + 1] += dp[i - 1][j];
      imos[j + 1] %= MOD;
      imos[R[i] + 1] += (MOD - dp[i - 1][j]);
      imos[R[i] + 1] %= MOD;
    }
    for (int j = 1; j <= N + 1; j++) {
      imos[j + 1] += imos[j];
      imos[j + 1] %= MOD;
    }
    for (int j = 1; j <= N + 1; j++) {
      dp[i][j] += imos[j];
      dp[i][j] %= MOD;
    }
  }
  cout << dp[N][N+1] << endl;
  return 0;
}
