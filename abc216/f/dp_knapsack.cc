// https://atcoder.jp/contests/abc216/tasks/abc216_f

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N;
  cin >> N;
  vector<pair<int, int> > AB(N);
  for (int n = 0; n < N; n++) {
    cin >> AB.at(n).first;
  }
  for (int n = 0; n < N; n++) {
    cin >> AB.at(n).second;
  }
  sort(AB.begin(), AB.end());
  // dp[i][j]: iまで見てBの和がjになる場合の数 (0<=i<=N, 0<=j<=5000)
  vector<vector<long long> > dp(N + 1, vector<long long>(5001, 0));
  dp[0][0] = 1;
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    int Ai = AB.at(i - 1).first;
    int Bi = AB.at(i - 1).second;
    for (int j = 1; j <= Ai; j++) {
      if (j - Bi >= 0) {
        ans += dp[i - 1][j - Bi];  // iを取る場合のみansに加算する
        ans %= MOD;
      }
    }
    for (int j = 0; j <= 5000; j++) {
      dp[i][j] = dp[i - 1][j];  // iを取らない
      if (j - Bi >= 0) {
        dp[i][j] += dp[i - 1][j - Bi];  // iを取る
        dp[i][j] %= MOD;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
