#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

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
  int K;
  cin >> K;
  vector<int> C(26);
  for (int i = 0; i < 26; i++) {
    cin >> C.at(i);
  }
  // dp[i][j]: アルファベットのi文字目(i=1がA)まで見て長さjの文字列の組合せの数
  vector<vector<mint>> dp(27, vector<mint>(K + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= C.at(i); k++) { // k: 足す長さ
        if (j + k <= K) {
          dp[i + 1][j + k] += dp[i][j] * COM(j + k, j);
        }
      }
    }
  }
  mint ans = 0;
  for (int k = 1; k <= K; k++) {
    ans += dp[26][k];
  }
  cout << ans << endl;
  return 0;
}
