// https://atcoder.jp/contests/abc225/tasks/abc225_f

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  sort(S.begin(), S.end(), [](string s, string t) { return s + t < t + s; });
  string INF;
  INF.push_back('z' + 1);
  // dp[i][j]: iまで見て、j個使った時の辞書順最小文字列
  vector<vector<string> > dp(N + 1, vector<string>(K + 1, INF));
  dp[N][0] = "";
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= K; j++) {
      // S[i]を使うとき
      int nj = j + 1;
      if (nj <= K) {
        dp[i][nj] = min(dp[i][nj], S[i] + dp[i + 1][j]);
      }
      // S[i]を使わない時
      dp[i][j] = min(dp[i][j], dp[i + 1][j]);
    }
  }
  cout << dp[0][K] << endl;
  return 0;
}
