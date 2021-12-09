// https://atcoder.jp/contests/abc210/tasks/abc210_d
// https://atcoder.jp/contests/abc210/editorial/2298

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000LL * (1000 * 1000 + 2) + 1;

long long solve(int H, int W, int C, vector<vector<int> >A) {
  vector<vector<long long> > dp(H + 1, vector<long long>(W + 1, INF));  // 1-indexed
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      long long a = A[i - 1][j - 1];  // 1-indexed --> 0-indexed
      dp[i][j] = min(dp[i - 1][j] + C, dp[i][j - 1] + C);
      dp[i][j] = min(dp[i][j], a);
    }
  }
  vector<vector<long long> > X(H + 1, vector<long long>(W + 1, INF));
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      long long a = A[i - 1][j - 1];  // 1-indexed --> 0-indexed
      X[i][j] = min(dp[i - 1][j] + C + a, dp[i][j - 1] + C + a);
    }
  }
  long long ans = INF;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      ans = min(ans, X[i][j]);
    }
  }
  return ans;
}

int main() {
  int H, W, C;
  cin >> H >> W >> C;
  vector<vector<int> > A(H, vector<int>(W, 0));  // 0-indexed
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  long long ans = solve(H, W, C, A);
  for (int i = 0; i < H; i++) {
    reverse(A[i].begin(), A[i].end());
  }
  ans = min(ans, solve(H, W, C, A));
  cout << ans << endl;
  return 0;
}
