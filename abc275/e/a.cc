#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<mint> > dp(K + 1, vector<mint>(N + 1, 0));
  dp[0][0] = 1;

  mint p = 1;
  mint q = M;
  p /= q;

  for (int i = 0; i <= K - 1; i++) {
    for (int j = 0; j <= N; j++) {
      if (j == N) {
        dp[i + 1][j] += dp[i][j];
        continue;
      }
      for (int k = 1; k <= M; k++) {
        int nj = j + k;
        if (nj > N) {
          int d = nj - N;
          nj = N - d;
        }
        assert(nj >= 0);
        dp[i + 1][nj] += dp[i][j] * p;
      }
    }
  }
  cout << dp[K][N].val() << endl;

  return 0;
}
