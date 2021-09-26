#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<vector<long long> > dp(10, vector<long long>(N, 0));
  const int MOD = 998244353;
  dp[A.at(0)][0] = 1;
  for (int n = 1; n < N; n++) {
    for (int k = 0; k < 10; k++) {
      dp[(A.at(n) + k) % 10][n] += dp[k][n - 1];
      dp[(A.at(n) + k) % 10][n] %= MOD;
      dp[(A.at(n) * k) % 10][n] += dp[k][n - 1];
      dp[(A.at(n) * k) % 10][n] %= MOD;
    }
  }
  for (int k = 0; k < 10; k++) {
    cout << dp[k][N - 1] << endl;
  }
  return 0;
}
