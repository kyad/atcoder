#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N + 1);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  const long long INF = 4e18;
  vector<vector<long long> > dp(N + 1, vector<long long>(M + 1, -INF));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - 1 >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + A[i] * j);
      }
    }
  }
  cout << dp[N][M] << endl;
  return 0;
}
