#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) {
  if (b > a) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  const double r = 0.9;
  const double A = 1200;
  int N;
  cin >> N;
  vector<double> P(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> P.at(n);
  }
  // Prepare Tk
  vector<double> T(N + 1, 0);
  T[1] = 1;
  for (int i = 2; i <= N; i++) {
    T.at(i) = 1. + r * T.at(i - 1);
  }
  const double INF = 4e18;
  vector<vector<double> > dp(N + 1, vector<double>(N + 1, -INF));
  vector<vector<double> > S(N + 1, vector<double>(N + 1, -1));
  dp[0][0] = -INF;
  S[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      // iを取らない
      if (chmax(dp[i][j], dp[i - 1][j])) {
        S[i][j] = S[i - 1][j];
      }
      // iを取る
      if (j >= 1) {
        if (j == 1) {  // 初めての時
          double now = P[i] - A;
          if (chmax(dp[i][j], now)) {
            S[i][j] = P[i];
          }
        } else {
          double dr = ((r * S[i - 1][j - 1] + P[i]) * T[j - 1] - S[i - 1][j - 1] * T[j]);
          dr /= (T[j - 1] * T[j]);
          dr += A * (1. / sqrt(j - 1) - 1. / sqrt(j));
          if (chmax(dp[i][j], dp[i - 1][j - 1] + dr)) {
            S[i][j] = S[i - 1][j - 1] * r + P[i];
          }
        }
      }
    }
  }
  double ans = -INF;
  for (int j = 1; j <= N; j++) {
    chmax(ans, dp[N][j]);
  }
  cout << setprecision(15) << ans << endl;
  return 0;
}
