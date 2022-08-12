// https://atcoder.jp/contests/typical90/tasks/typical90_s

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(2 * N);
  for (int n = 0; n < 2 * N; n++) { cin >> A.at(n); }
  const int INF = 400000001;
  // dp[i][j]: iからjまでを取り除く時のコストの最小値(0<=i<2*N, 0<=j<2*N)
  vector<vector<int> > dp(2 * N, vector<int>(2 * N, INF));
  // 長さ2
  for (int i = 0; i <= 2 * N - 2; i++) { dp[i][i + 1] = abs(A[i] - A[i + 1]); }
  for (int l = 4; l <= 2 * N; l += 2) {  // 長さl
    for (int i = 0; i < 2 * N; i++) {
      int j = i + l - 1;
      if (j >= 2 * N) { continue; }
      dp[i][j] = dp[i + 1][j - 1] + abs(A[i] - A[j]);
      for (int k = i + 2; k <= j - 1; k += 2) {
        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j]);
      }
    }
  }
  cout << dp[0][2 * N - 1] << endl;
  return 0;
}
