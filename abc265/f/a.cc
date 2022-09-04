// https://atcoder.jp/contests/abc265/tasks/abc265_f

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> P(N + 1, 0), Q(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> P.at(n);
  }
  for (int n = 1; n <= N; n++) {
    cin >> Q.at(n);
  }
  // dp[i][j][k]: i次元まで見た時にPからの距離がj、Qからの距離がkの個数
  // 1<=i<=N, 0<=j<=D, 0<=k<=D
  vector<vector<long long> > dp(D + 1, vector<long long>(D + 1, 0));

  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    int r = abs(P[i] - Q[i]);
    vector<vector<long long> > p(D + 1, vector<long long>(D + 1, 0));
    vector<vector<long long> > s1(dp);
    for (int j = 1; j <= D; j++) {
      for (int k = 1; k <= D; k++) {
        s1[j][k] += s1[j - 1][k - 1];
        s1[j][k] %= MOD;
      }
    }
    vector<vector<long long> > s2(dp);
    for (int j = 1; j <= D; j++) {
      for (int k = D - 1; k >= 0; k--) {
        s2[j][k] += s2[j - 1][k + 1];
        s2[j][k] %= MOD;
      }
    }
    swap(p, dp);
    auto sum1 = [&](int j, int k) -> long long {
      if (j < 0 || k < 0) {
        return 0;
      }
      return s1[j][k];
    };
    auto sum2 = [&](int sj, int sk) -> long long {
      int tj = sj - r - 1;
      int tk = sk + r + 1;
      if (sk < 0) {
        sj += sk;
        sk = 0;
      }
      if (sj < 0) {
        return 0;
      }
      long long ans = s2[sj][sk];
      if (tj >= 0 && tk <= D) {
        ans += (MOD - s2[tj][tk]);
        ans %= MOD;
      }
      return ans;
    };
    for (int j = 0; j <= D; j++) {
      for (int k = 0; k <= D; k++) {
        dp[j][k] += sum1(j - 1, k - r - 1);
        dp[j][k] %= MOD;
        dp[j][k] += sum1(j - r - 1, k - 1);
        dp[j][k] %= MOD;
        dp[j][k] += sum2(j, k - r);
        dp[j][k] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= D; j++) {
    for (int k = 0; k <= D; k++) {
      ans += dp[j][k];
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
