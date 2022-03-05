#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N;
  cin >> N;
  vector<vector<long long> > dp(N, vector<long long>(10, 0));
  for (int j = 1; j <= 9; j++) {
    dp[0][j] = 1;
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = 1; j <= 9; j++) {
      for (int dj = -1; dj <= 1; dj++) {
        int nj = j + dj;
        if (nj < 1 || nj > 9) {
          continue;
        }
        dp[i + 1][nj] += dp[i][j];
        dp[i + 1][nj] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int j = 1; j <= 9; j++) {
    ans += dp[N - 1][j];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
