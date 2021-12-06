// https://atcoder.jp/contests/abc230/tasks/abc230_f

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  const int MOD = 998244353;
  int N;
  cin >> N;
  vector<long long> sum(N + 1);
  sum.at(0) = 0;
  for (int n = 1; n <= N; n++) {
    int A;
    cin >> A;
    sum.at(n) = sum.at(n - 1) + A;
  }
  sum.erase(sum.begin());
  sum.pop_back();
  // dp[n+1]: n個目を最後に使う場合の部分列の個数 (0<n<N-1)
  // dp[0]: 何も選ばない場合の部分列の個数
  vector<int> dp(N, 0);
  // dp[n] = dp_sum[n + 1] - dp_sum[n]
  vector<int> dp_sum(N + 1, 0);
  map<long long, int> mp;
  dp[0] = 1;  // 何も選ばない
  dp_sum[0] = 0;
  dp_sum[1] = dp[0];
  for (int n = 0; n < N - 1; n++) {
    int start = -1;
    if (mp.count(sum[n]) > 0) {
      start = mp[sum[n]];
    }
    // for (int k = start; k < n; k++) {
    //   dp[n + 1] += dp[k + 1];
    //   dp[n + 1] %= MOD;
    // }
    dp[n + 1] = dp_sum[n + 1] - dp_sum[start + 1] + MOD;
    dp[n + 1] %= MOD;
    dp_sum[n + 2] = dp_sum[n + 1] + dp[n + 1];
    dp_sum[n + 2] %= MOD;
    mp[sum[n]] = n;
  }
  cout << dp_sum[N] << endl;
  return 0;
}
