#include <iostream>
#include <vector>
using namespace std;

void print(int n, int d) {
  for (int i = 0; i < n; i++) {
    cout << d;
  }
  cout << endl;
}

int main() {
  int N, M;
  cin >> N >> M;
  // dp[n][d] = x(n, d) mod M
  vector<vector<long long> > dp(N + 1, vector<long long>(10));
  for (int n = 1; n <= N; n++) {
    for (int d = 1; d <= 9; d++) {
      dp[n][d] = 10 * dp[n - 1][d] + d;
      dp[n][d] %= M;
    }
  }
  for (int n = N; n >= 1; n--) {
    for (int d = 9; d >= 1; d--) {
      if (dp[n][d] == 0) {
        print(n, d);
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
