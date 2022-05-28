// https://atcoder.jp/contests/abc252/tasks/abc252_g

#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  // dp[i][j]: [i, j)までのPの範囲における根付き木の個数
  vector<vector<mint> > dp(N + 1, vector<mint>(N + 1, 0));
  for (int l = 0; l <= N; l++) {
    dp[l][l] = 1;
  }
  for (int w = 1; w <= N; w++) {
    for (int l = 0; l < N; l++) {
      int r = l + w;
      if (r > N) {
        continue;
      }
      dp[l][r] += dp[l + 1][r];
      for (int k = l + 2; k < r; k++) {
        if (P[l + 1] > P[k]) {
          continue;
        }
        dp[l][r] += dp[l + 1][k] * dp[k - 1][r];
      }
    }
  }
  cout << dp[0][N].val() << endl;
  return 0;
}
