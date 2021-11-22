// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int INF = 100 * 200 + 1;
  int D, N;
  cin >> D >> N;
  vector<int> T(D, 0);
  for (int d = 0; d < D; d++) {
    cin >> T.at(d);
  }
  vector<int> A(N), B(N), C(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n) >> C.at(n);
  }
  // dp[d][n]: d(0-indexed)日目にn(0-indexed)の服を着た時の、d日目までの派手さの差の絶対値の和の最大値
  // d日目に服nを着られない時は-INF
  vector<vector<int> > dp(D, vector<int>(N, 0));
  for (int d = 0; d < D; d++) {
    for (int n = 0; n < N; n++) {
      if (A.at(n) <= T.at(d) && T.at(d) <= B.at(n)) {
        if (d == 0) {  // 1日目の時
          dp[d][n] = 0;
        } else {
          for (int m = 0; m < N; m++) {
            dp[d][n] = max(dp[d][n], dp[d - 1][m] + abs(C.at(m) - C.at(n)));
          }
        }
      } else {
        dp[d][n] = -INF;
      }
    }
  }
  cout << *max_element(dp[D - 1].begin(), dp[D - 1].end()) << endl;
  return 0;
}
