#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  const int T = 100000;
  vector<int> X(T + 1, -1);
  vector<long long> A(T + 1, -1);
  for (int n = 0; n < N; n++) {
    int t, x;
    long long a;
    cin >> t >> x >> a;
    X[t] = x;
    A[t] = a;
  }
  const long long INF = 4e18;
  vector<vector<long long> > dp(T + 1, vector<long long>(5, -INF));
  dp[0][0] = 0;
  for (int i = 1; i <= T; i++) {
    for (int j = 0; j < 5; j++) {
      // Update dp[i][j]
      for (int k = -1; k <= 1; k++) {
        int pj = j + k;  // previous j
        if (pj < 0 || pj >= 5) {
          continue;
        }
        long long now = dp[i - 1][pj];
        if (j == X[i]) {
          now += A[i];
        }
        dp[i][j] = max(dp[i][j], now);
      }
    }
  }
  cout << *max_element(dp[T].begin(), dp[T].end()) << endl;
  return 0;
}
