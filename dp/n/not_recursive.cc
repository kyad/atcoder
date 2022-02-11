// https://atcoder.jp/contests/dp/tasks/dp_n

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const long long INF = 1LL<<60;
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  vector<long long> S(N + 1, 0); // S[n] = a[1] + ... + a[n] (1-indexed)
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
    S[n] = S[n - 1] + A[n];
  }
  // dp[i][j]: iからjまでのスライムを合体させるまでのコストの最小値 (1-indexed)
  vector<vector<long long> >dp(N + 1, vector<long long>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      dp[i][j] = i == j ? 0 : INF;
    }
  }
  for (int len = 1; len < N; len++) {
    for (int i = 1; i <= N; i++) {
      int j = i + len;
      if (j > N) {
        break;
      }
      long long mn = INF;
      for (int k = i; k < j; k++) {
        mn = min(mn, dp[i][k] + dp[k + 1][j]);
      }
      dp[i][j] = mn + S[j] - S[i - 1];
    }
  }
  cout << dp[1][N] << endl;
  return 0;
}
