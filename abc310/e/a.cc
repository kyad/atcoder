#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');
  vector<vector<long long> > dp(N + 1, vector<long long>(2, 0));
  for (int i = 1; i <= N; i++) {
    if (S[i] == '0') {
      dp[i][0] = 0;
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][0]++;
    } else {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0];
      dp[i][1]++;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += dp[i][1];
  }
  cout << ans << endl;
  return 0;
}
