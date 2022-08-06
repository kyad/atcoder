// https://atcoder.jp/contests/typical90/tasks/typical90_o

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 510000;  // n (<= 10^7)
const int MOD = 1000000007;  // p (prime, > n)

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
  int N;
  cin >> N;
  COMinit();
  for (int k = 1; k <= N; k++) {
    long long ans = 0;
    int T = (N - 1) / k + 1;
    for (int a = 1; a <= T; a++) {
      ans += COM(N - (k - 1) * (a - 1), a);
      ans %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
