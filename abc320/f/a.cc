#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, H;
  cin >> N >> H;
  vector<int> X(N + 1, 0);  // 1-indexed
  for (int i = 1; i <= N; i++) {
    cin >> X.at(i);
  }
  vector<long long> P(N + 1, 0);  // 1-indexed
  vector<int> F(N + 1, 0);  // 1-indexed
  for (int i = 1; i <= N - 1; i++) {
    cin >> P.at(i) >> F.at(i);
  }

  // D[i]: i-1からiまでの距離
  vector<int> D(N + 1, 0); // 1-indexed
  for (int i = 1; i <= N; i++) {
    D.at(i) = X.at(i) - X.at(i - 1);
  }

  const long long INF = 4e18;
  vector<vector<vector<long long> > > dp(N, vector<vector<long long> > (H + 1, vector<long long>(H + 1, INF)));
  for (int k = D[1]; k <= H; k++) {
    dp[0][H][k] = 0;
  }
  for (int i = 0; i <= N - 2; i++) {
    for (int j = 0; j <= H; j++) {
      if (j - D[i + 1] < 0) {
        continue;
      }
      for (int nk = 0; nk <= H; nk++) {
        if (nk - D[i + 2] < 0) {
          continue;
        }
        int nj0 = j - D[i + 1];
        int nj1 = min(H, nj0 + F[i + 1]);
        int k0 = nk - D[i + 2];
        int k1 = min(H, k0 + F[i + 1]);
        // i+1を使わない
        chmin(dp[i + 1][nj0][nk], dp[i][j][k0]);
        // i+1を行きで使う
        chmin(dp[i + 1][nj1][nk], dp[i][j][k0] + P[i + 1]);
        // i+1を帰りで使う
        chmin(dp[i + 1][nj0][nk], dp[i][j][k1] + P[i + 1]);
      }
    }
  }
  long long ans = INF;
  for (int j = D[N] * 2; j <= H; j++) {
    int k = j - D[N];
    chmin(ans, dp[N - 1][j][k]);
  }
  if (ans >= INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
