// https://www.youtube.com/watch?v=xkxD0P1io7Y&t=7426s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<double> P(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> P.at(i);
    P.at(i) /= (double)100;
  }
  // dp1[i][k]: iまで見た時にレアがk枚含まれる確率
  vector<vector<double> > dp1(N + 1, vector<double>(N + 1, 0));
  dp1[0][0] = 1.;
  for (int i = 1; i <= N; i++) {
    for (int k = 0; k <= N; k++) {
      dp1[i][k] = dp1[i - 1][k - 1] * P.at(i) + dp1[i - 1][k] * (1 - P.at(i));
    }
  }
  //q[k]: 1回パックを開けた時にレアがk枚の確率
  const vector<double> &q = dp1[N];

  // dp[i]: 残りのレア枚数iから0枚に達するまでのパック数の期待値(i<0はi=0に込める)
  vector<double> dp(X + 1, 0);
  for (int i = 1; i <= X; i++) {
    double now = 1;
    for (int j = 1; j <= N; j++) {
      now += q.at(j) * dp.at(max(i - j, 0));  // i<0はi=0に込める
    }
    dp.at(i) = now / (1 - q.at(0));
  }
  double ans = dp.at(X);
  cout << setprecision(15) << ans << endl;
  return 0;
}

