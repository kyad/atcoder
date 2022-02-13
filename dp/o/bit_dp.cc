// https://atcoder.jp/contests/dp/tasks/dp_o

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 1000000007;
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  int N2 = 1 << N;
  // dp[s]: 対応がsまで確定している時の組合せの総数
  vector<long long> dp(N2, 0);
  dp[0] = 1;
  for (int s = 0; s < N2; s++) {  // 配るDP
    int i = __builtin_popcount(s);
    for (int x = 0; x < N; x++) {  // 遷移先
      if ((s >> x) & 1) {
        continue;
      }
      if (!A.at(i).at(x)) {
        continue;
      }
      int ns = s | (1<<x);
      dp[ns] += dp[s];
      dp[ns] %= MOD;
    }
  }
  cout << dp[N2 - 1] << endl;
  return 0;
}
