#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 510000;  // n (<= 10^7)
const int MOD = 998244353;  // p (prime, > n)

long long fac[MAX];  // a! mod p
long long finv[MAX];  // (a!)^{-1} mod p
long long inv[MAX];  // a^{-1} mod p

// O(n)
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// nCk mod p, O(1)
long long COM(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();
  string S;
  cin >> S;
  vector<int> count(26, 0);
  for (size_t i = 0; i < S.size(); i++) {
    count[S[i] - 'a']++;
  }
  vector<vector<long long> > dp(26, vector<long long>(5001, 0));
  int c = 0;
  for (int i = 1; i <= count[c]; i++) {
    dp[c][i]++;
  }
  for (int c = 1; c < 26; c++) {
    for (int i = 1; i <= 5000; i++) {
      dp[c][i] = dp[c - 1][i];
    }
    // only c
    for (int i = 1; i <= count[c]; i++) {
      dp[c][i]++;
      dp[c][i] %= MOD;
    }
    for (int k = 1; k <= count[c]; k++) {
      for (int i = 1; i <= 5000; i++) {
        if (i + k > 5000) {
          continue;
        }
        dp[c][i + k] += dp[c - 1][i] * COM(i + k, k);
        dp[c][i + k] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 5000; i++) {
    ans += dp[25][i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
