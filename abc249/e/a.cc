// https://atcoder.jp/contests/abc249/tasks/abc249_e

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P;
  cin >> N >> P;
  // dp[i][j]: |S|=j, |T|=i となるSの個数
  vector<vector<long long> > dp(3001, vector<long long>(3001, 0));
  dp[0][0] = 1;
  for (int i = 0; i <= 3000; i++) {
    if (i > 0) {
      // imos --> normal
      for (int j = 1; j <= 3000; j++) {
        dp[i][j] += dp[i][j - 1];
      }
    }
    for (int j = 0; j <= 3000; j++) {
      const int ten[] = {1, 10, 100, 1000, 10000};
      for (int k = 0; k < 4; k++) {
        int ni = i + k + 2;
        int L = j + ten[k];
        int R = j + ten[k + 1];
        if (ni > 3000) {
          continue;
        }
        long long now = dp[i][j] * (i == 0 ? 26 : 25);
        now %= P;
        if (L <= 3000) {
          dp[ni][L] += now;
          dp[ni][L] %= P;
        }
        if (R <= 3000) {
          dp[ni][R] += (P - now);
          dp[ni][R] %= P;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    ans += dp[i][N];
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}
