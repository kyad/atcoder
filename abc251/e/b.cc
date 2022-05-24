// https://atcoder.jp/contests/abc251/tasks/abc251_e

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  const long long INF = 1e18;
  // dp[i][j][k]: 枝N-1を{i=0:取らない、i=1:取る}と予言した時で、
  // 枝jを{k=0:取らない、k=1:取る}時、j+1個目までつなげる時のコストの最小値
  vector<vector<vector<long long> > > dp(2, vector<vector<long long> >(N, vector<long long>(2)));
  dp[0][0][0] = INF;
  dp[0][0][1] = A[0];
  dp[1][0][0] = 0;
  dp[1][0][1] = A[0];
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < N; j++) {
      dp[i][j][0] = dp[i][j - 1][1];
      dp[i][j][1] = min(dp[i][j - 1][0] + A[j], dp[i][j - 1][1] + A[j]);
    }
  }
  long long ans = INF;
  for (int i = 0; i < 2; i++) {
    ans = min(ans, dp[i][N - 1][i]);  // 予言が当たった(i == k)場合のみ考える
  }
  cout << ans << endl;
  return 0;
}
