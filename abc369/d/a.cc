#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  const long long INF = 4e18;
  vector<vector<long long> > dp(N + 1, vector<long long>(2, -INF));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + A.at(i) * 2);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + A.at(i));
  }
  long long ans = max(dp[N][0], dp[N][1]);
  cout << ans << endl;
  return 0;
}
