#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');
  // dp[i][j]: i回目にjを出した時、高橋くんが勝った最大数
  // j=0 グー j=1 チョキ j=2 パー
  const int INF = 1e9;
  vector<vector<int> > dp(N + 1, vector<int>(3, 0));
  for (int i = 1; i <= N; i++) {
    if (S[i] == 'R') { // 青木君がグーの
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);  // あいこ
      dp[i][1] = -INF;   // ありえない
      dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;  // 勝つ
    } else if (S[i] == 'S') { // 青木君がチョキの時
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;  // 勝つ
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);  // あいこ
      dp[i][2] = -INF;   // ありえない
    } else { // 青木君がパーの時
      dp[i][0] = -INF;   // ありえない
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;  // 勝つ
      dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);  // あいこ
    }
  }
  int ans = -INF;
  for (int j = 0; j < 3; j++) {
    ans = max(ans, dp[N][j]);
  }
  assert(ans >= 0);
  cout << ans << endl;
  return 0;
}
