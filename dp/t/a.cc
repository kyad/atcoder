// https://atcoder.jp/contests/dp/tasks/dp_t

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MOD = 1000000007;
  int N;
  cin >> N;
  string S;
  cin >> S;
  // iまで見た時にi番目より大きい数からj個残っている場合の数
  vector<vector<long long> > dp(N, vector<long long>(N, 0));
  for (int j = 0; j < N; j++) {
    dp[0][j] = 1;
  }
  for (int i = 1; i < N; i++) {
    vector<long long> cum(dp[i - 1]);
    cum.insert(cum.begin(), 0);
    for (int j = 0; j < N; j++) {
      cum[j + 1] += cum[j];
    }
    auto sum = [&cum](int min, int max) -> long long {
      long long ans = cum[max + 1] - cum[min];
      ans %= MOD;
      return ans;
    };
    if (S[i - 1] == '<') {
      for (int j = 0; j < N - i; j++) {
        dp[i][j] = sum(j + 1, N - i);
        dp[i][j] %= MOD;
      }
    } else {
      for (int j = 0; j < N - i; j++) {
        dp[i][j] = sum(0, j);
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[N - 1][0] << endl;
  return 0;
}
