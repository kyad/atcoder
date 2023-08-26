#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N;
  cin >> N;
  vector<long long> X(N + 1, -1);
  vector<long long> Y(N + 1, -1);
  vector<long long> Z(N + 1, -1);
  for (int n = 1; n <= N; n++) {
    cin >> X.at(n) >> Y.at(n) >> Z.at(n);
  }
  const long long INF = 4e18;
  const int M = 100000;
  vector<vector<long long> > dp(N + 1, vector<long long>(M + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (X[i] > Y[i]) {
        if (j - Z[i] >= 0) {
          dp[i][j] = dp[i - 1][j - Z[i]];
        }
      } else {
        // 負ける
        chmin(dp.at(i).at(j), dp.at(i - 1).at(j));
        // 勝つ
        if (j - Z[i] >= 0) {
          chmin(dp.at(i).at(j), dp.at(i - 1).at(j - Z.at(i)) + (Y.at(i) - X.at(i) + 1) / 2);
        }
      }
    }
  }
  long long Zsum = 0;
  for (int n = 1; n <= N; n++) {
    Zsum += Z[n];
  }
  long long L = (Zsum + 1) / 2;
  long long ans = INF;
  for (int j = L; j <= M; j++) {
    chmin(ans, dp.at(N).at(j));
  }
  cout << ans << endl;
  return 0;
}
