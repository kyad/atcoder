#include <bits/stdc++.h>
using namespace std;

long long dp[1024][10][1001];

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (int n = 1; n <= N; n++) { // 1000
    int c = S[n - 1] - 'A';
    for (int j = 0; j < 10; j++) { // 10^4
      if (j == c) {
        dp[0][j][n] = dp[0][j][n - 1] * 2 + 1;  // i == 0
        dp[0][j][n] %= 998244353;
        for (int i = 1; i < 1024; i++) { // 10^7
          if (i & (1 << c)) {
            continue;
          }
          dp[i][j][n] = dp[i][j][n - 1] * 2;
          dp[i][j][n] %= 998244353;
          for (int jj = 0; jj < 10; jj++) { // 10^8
            if (! (i & (1 << jj)) ) {
              continue;
            }
            int ii = i - (1 << jj);
            dp[i][j][n] += dp[ii][jj][n - 1];
            dp[i][j][n] %= 998244353;
          }
        }
      } else {
        for (int i = 0; i < 1024; i++) {
          dp[i][j][n] = dp[i][j][n - 1];
          dp[i][j][n] %= 998244353;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 1024; i++) {
    for (int j = 0; j < 10; j++) {
      ans += dp[i][j][N];
      ans %= 998244353;
    }
  }
  cout << ans << endl;
  return 0;
}
