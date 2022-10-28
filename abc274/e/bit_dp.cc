#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double dist(double x, double y) {
  return sqrt(x * x + y * y);
}

int main() {
  int N, M;
  cin >> N >> M;
  int L = N + M;
  vector<int> X(L), Y(L);
  for (int n = 0; n < N; n++) {
    cin >> X.at(M + n) >> Y.at(M + n);
  }
  for (int m = 0; m < L; m++) {
    cin >> X.at(m) >> Y.at(m);
  }
  int L2 = 1<<L;
  const double INF = 1e300;
  // dp[i][j]: iを全部通る時の最小値で、最後がj
  // i = 0, 1, ..., 1<<L
  // j = 0, 1, ..., L-1
  vector<vector<double> > dp(L2, vector<double>(L, INF));
  for (int j = 0; j < L; j++) {
    dp[1<<j][j] = dist(X[j], Y[j]);
  }
  // 配るDP
  for (int i = 1; i < L2; i++) {
    int boost = __builtin_popcount(i & ((1<<M) - 1));
    for (int j = 0; j < L; j++) {
      for (int nj = 0; nj < L; nj++) {
        if ((i >> nj) & 1) {
          continue;
        }
        int ni = i | (1 << nj);
        dp[ni][nj] = min(dp[ni][nj], dp[i][j] + dist(X[j] - X[nj], Y[j] - Y[nj]) / (1<<boost));
      }
    }
  }
  double ans = INF;
  for (int k = 0; k < (1<<M); k++) {
    int i = (((1<<N) - 1) << M) | k;  // 111111....10....0|k
    int boost = __builtin_popcount(k);
    for (int j = M; j < L; j++) {
      double now = dp[i][j] + dist(X[j], Y[j]) / (1<<boost);
      ans = min(ans, now);
    }
  }
  cout << setprecision(15) << ans << endl;
  return 0;
}
