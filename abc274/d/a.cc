#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  auto solve = [&](bool odd) {
    // dp[i][j]: A[i]までとった時に、jになれるか？
    const int M = 10000;
    vector<vector<bool> > dp(N + 1, vector<bool>(2 * M + 1, false));
    if (odd) {
      dp[1][A[1] + M] = true;
      dp[2][A[1] + M] = true;
    } else {
      dp[2][A[2] + M] = true;
      dp[2][-A[2] + M] = true;
    }
    for (int i = 3; i <= N; i++) {
      for (int j = -M; j <= M; j++) {
        if ((odd && i % 2 == 0) || (odd == false && (i % 2 == 1))) {
          dp[i][j + M] = dp[i - 1][j + M];
          continue;
        }
        if (!dp[i - 1][j + M]) {
          continue;
        }
        const int d[2] = {-1, 1};
        for (int k = 0; k < 2; k++) {
          int nj = j + A[i] * d[k];
          assert(nj >= -M);
          assert(nj <= M);
          dp[i][nj + M] = true;
        }
      }
    }
    bool ans;
    if (odd) {
      ans = dp[N][X + M];
    } else {
      ans = dp[N][Y + M];
    }
    return ans;
  };
  bool ans_odd = solve(true);
  bool ans_even = solve(false);
  cout << (ans_odd && ans_even ? "Yes" : "No") << endl;
  return 0;
}
