// https://atcoder.jp/contests/abc242/tasks/abc242_e

#include <iostream>
#include <vector>
using namespace std;

void testcase(int t) {
  const int MOD = 998244353;
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  if (N % 2 == 1) {
    K = N / 2;
  } else {
    K = N / 2 - 1;
  }
  // dp[i][smaller]: i文字目(1-indexed)まで見た時に置ける回文の個数
  // smaller==1: 真に小さいことが確定している
  vector<vector<long long> > dp(N + 1, vector<long long>(2, 0));
  dp[0][0] = 1;
  dp[0][1] = 0;
  bool smaller_ok = false;
  for (int i = 0; i < N; i++) {
    int ni = i + 1;
    // smaller == 0
    if (i <= K) {
      dp[ni][0] = 1;
    } else {
      if (smaller_ok || S[i] > S[N - 1 - i]) {
        smaller_ok = true;
        dp[ni][0] = dp[ni - 1][0];
      } else if (S[i] == S[N - 1 - i]) {
        dp[ni][0] = dp[ni - 1][0];
      }
    }
    // smaller == 1
    if (i <= K) {
      dp[ni][1] += (S[i] - 'A');
      dp[ni][1] += dp[ni - 1][1] * 26;
      dp[ni][1] %= MOD;
    } else {
      dp[ni][1] = dp[ni - 1][1];
    }
  }
  long long ans = 0;
  for (int smaller = 0; smaller < 2; smaller++) {
    ans += dp[N][smaller];
    ans %= MOD;
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase(t);
  }
  return 0;
}
