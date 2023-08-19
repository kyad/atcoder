// https://www.youtube.com/watch?v=fDJpXN2R75A

#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/**
 * 距離の2乗を返す
 */
template<typename T> T dist2(T x0, T y0, T x1, T y1) {
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }

  const int M = 1 + (log(4e10*sqrt(2) * N) / log(2)) + 1;

  const double INF = 4e48;
  vector<vector<double> > dp(N, vector<double>(M + 1, INF));
  dp[0][0] = 0;

  auto dist = [&](int u, int v) -> double {
    double d = dist2(X[u], Y[u], X[v], Y[v]);
    return sqrt(d);
  };

  vector<double> S(M + 1, 0);
  for (int c = 1; c <= M; c++) {
    S[c] = pow(2, c - 1);
  }

  for (int i = 0; i <= N - 2; i++) {
    for (int j = 0; j <= M; j++) {
      for (int d = 0; d < N; d++) {  // d: 飛ばす数
        const int ni = i + d + 1;
        if (ni >= N) {
          break;
        }
        const int nj = j + d;
        if (nj > M) {
          continue;
        }
        double now = dp[i][j] + dist(i, ni) + (S[nj] - S[j]);
        dp[ni][nj] = min(dp[ni][nj], now);
      }
    }
  }
  double ans = *min_element(dp[N - 1].begin(), dp[N - 1].end());
  cout << setprecision(15) << ans <<endl;
  return 0;
}
