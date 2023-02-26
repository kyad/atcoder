#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N;
  cin >> N;
  vector<int> A(N + 1, 0), B(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  vector<vector<long long> > dp(N + 1, vector<long long>(2, 0));
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int pj = 0; pj < 2; pj++) {
        int p = (pj == 1 ? A[i - 1] : B[i - 1]);
        int n = (j == 1 ? A[i] : B[i]);
        if (n != p) {
          dp[i][j] += dp[i - 1][pj];
          dp[i][j] %= MOD;
        }
      }
    }
  }
  long long ans = dp[N][0] + dp[N][1];
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
