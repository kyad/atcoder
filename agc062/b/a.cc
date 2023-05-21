#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> C(N);
  for (int k = 0; k < K; k++) {
    cin >> C.at(k);
  }
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P[n]--;  // 0-indexed
  }
  const long long INF = 4e18;
  vector<vector<vector<long long> > > dp(K + 1, vector<vector<long long> >(N + 1, vector<long long>(N + 1, INF)));
  // dp[i][l][l]
  for (int i = 0; i <= K; i++) {
    for (int l = 0; l <= N; l++) {
      dp[i][l][l] = 0;
      if (l + 1 <= N) {
        dp[i][l][l + 1] = 0;
      }
    }
  }  
  // dp[K]
  for (int l = 0; l < N; l++) {
    int p = find(P.begin(), P.end(), l) - P.begin();
    for (int r = l; r < N; r++) {
      int q = find(P.begin(), P.end(), r) - P.begin();
      if (p <= q) {
        dp[K][l][r + 1] = 0;
        p = q;
      } else {
        break;
      }
    }
  }
  // Range DP
  for (int i = K - 1; i >= 0; i--) {
    for (int l = 0; l < N; l++) {
      for (int r = l; r <= N; r++) {
        for (int k = 0; k <= N - 1; k++) {
          if (r - k < 0) {
            continue;
          }
          long long now = dp[i + 1][l][r - k] + dp[i + 1][r - k][r] + C[i] * k;
          chmin(dp[i][l][r], now);
        }
      }
    }
  }
  long long ans = dp[0][0][N];
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
