// https://atcoder.jp/contests/abc248/tasks/abc248_f

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P;
  cin >> N >> P;
  // dp[i][j][k]: 頂点数が2*(i+1)の時、j本の辺を取り除いて、
  // 残りも連結(k==0)・次で頑張れば連結になる(k==1)個数  
  vector<vector<vector<long long> > > dp(N, vector<vector<long long> >(N, vector<long long>(2, 0)));
  dp[0][0][0] = 1;
  dp[0][1][1] = 1;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      dp[i + 1][j][0] += dp[i][j][0];
      dp[i + 1][j][0] %= P;
      if (j + 1 < N) {
        dp[i + 1][j + 1][0] += dp[i][j][0] * 3;
        dp[i + 1][j + 1][0] %= P;
      }

      if (j + 2 < N) {
        dp[i + 1][j + 2][1] += dp[i][j][0] * 2;
        dp[i + 1][j + 2][1] %= P;
      }
      
      dp[i + 1][j][0] += dp[i][j][1];
      dp[i + 1][j][0] %= P;

      if (j + 1 < N) {
        dp[i + 1][j + 1][1] += dp[i][j][1];
        dp[i + 1][j + 1][1] %= P;
      }
    }
  }
  for (int j = 1; j <= N - 1; j++) {
    cout << dp[N - 1][j][0] << (j == N - 1 ? '\n' : ' ');
  }
  return 0;
}
