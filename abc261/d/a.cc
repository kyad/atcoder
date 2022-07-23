#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  const long long INF = 4e18;
  vector<long long> X(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> X.at(n);
  }
  vector<long long> Y(N + 1, 0);
  for (int m = 0; m < M; m++) {
    int C;
    cin >> C;
    cin >> Y.at(C);
  }
  vector<vector<long long> > dp(N + 1, vector<long long>(N + 1, -INF));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
    for (int j = 1; j <= N; j++) {
      dp[i][j] = dp[i - 1][j - 1] + X.at(i) + Y.at(j);
    }
  }
  cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
  return 0;
}
