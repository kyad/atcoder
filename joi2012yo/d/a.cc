// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> reserved(N + 1, -1);
  for (int k = 0; k < K; k++) {
    int A, B;
    cin >> A >> B;
    reserved[A - 1] = B - 1;
  }
  vector<vector<vector<int> > > dp(3, vector<vector<int> >(3, vector<int>(N, 0)));
  for (int p0 = 0; p0 < 3; p0++) {
    if (reserved[0] >= 0 && reserved[0] != p0) {
      continue;
    }
    for (int p1 = 0; p1 < 3; p1++) {
      if (reserved[1] >= 0 && reserved[1] != p1) {
        continue;
      }
      dp[p0][p1][1] = 1;
    }
  }
  const int MOD = 10000;
  for (int n = 2; n < N; n++) {
    for (int p = 0; p < 3; p++) {
      if (reserved[n] >= 0 && reserved[n] != p) {
        continue;
      }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (i == j && j == p) {
            continue;
          }
          dp[j][p][n] += dp[i][j][n - 1];
          dp[j][p][n] %= MOD;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ans += dp[i][j][N - 1];
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
