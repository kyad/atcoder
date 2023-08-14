// https://www.youtube.com/watch?v=4izGr03w6r0

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> C(N), P(N);
  vector<vector<int> > S(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i) >> P.at(i);
    S.at(i).resize(P.at(i));
    for (int j = 0; j < P[i]; j++) {
      cin >> S.at(i).at(j);
    }
  }
  vector<double> dp(M + 1, 0);
  for (int k = 1; k <= M; k++) {
    dp[k] = 4e18;  // INF
    for (int i = 0; i < N; i++) {
      double now = 0;
      int nz = 0;
      for (int j = 0; j < P[i]; j++) {
        if (S[i][j] == 0) {
          nz++;
        } else {
          now += dp[max(0, k - S[i][j])];
        }
      }
      now /= P[i];
      now += C[i];
      now /= (1. - (double)nz/P[i]);
      dp[k] = min(dp[k], now);
    }
  }
  cout << setprecision(15) << dp[M] << endl;
  return 0;
}
