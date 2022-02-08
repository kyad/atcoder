// https://atcoder.jp/contests/abc238/tasks/abc238_f

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N, K;
  cin >> N >> K;
  vector<pair<int, int> > PQ(N);
  for (int n = 0; n < N; n++) {
    cin >> PQ.at(n).first;
  }
  vector<int> Q(N);
  for (int n = 0; n < N; n++) {
    cin >> PQ.at(n).second;
  }
  sort(PQ.begin(), PQ.end());
  // Pの上位からi(1<i<=N)人目まで見て、選ばなかった人の最小順位k(1<=k<=N)でj(0<=j<=N)人選ぶ組合せの数
  // 301 * 301 * 302 = 2.7*10^7
  vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> >(N + 1, vector<long long>(N + 2, 0)));
  const int INF = N + 1;
  dp[0][0][INF] = 1;
  for (int i = 1; i <= N; i++) {
    int q = PQ.at(i - 1).second;  // i人目
    for (int j = 0 ; j < N; j++) {
      // i人目を取らない
      for (int k = 1; k <= INF; k++) {
        dp[i][j][min(k, q)] += dp[i - 1][j][k];
        dp[i][j][min(k, q)] %= MOD;
      }
      // i人目を取る
      for (int k = q + 1; k <= INF; k++) {
        dp[i][j + 1][k] += dp[i - 1][j][k];
        dp[i][j + 1][k] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int k = 1; k <= INF; k++) {
    ans += dp[N][K][k];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
