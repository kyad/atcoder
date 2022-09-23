// https://atcoder.jp/contests/abc266/tasks/abc266_g

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4000002;  // n (<= 10^7)
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

int main() {
  COMinit();
  long long R, G, B, K;
  cin >> R >> G >> B >> K;
  R -= K;
  G -= K;
  long long sgn = 1;
  long long ans = 0;
  long long I = min(R, G);
  for (long long i = 0; i <= I; i++) {
    long long N = (R - i) + (G - i) + B + K + i;
    long long now = fac[N];
    now *= finv[R - i];
    now %= MOD;
    now *= finv[G - i];
    now %= MOD;
    now *= finv[B];
    now %= MOD;
    now *= finv[K];
    now %= MOD;
    now *= finv[i];
    now %= MOD;
    if (sgn < 0) {
      now = (MOD - now);
    }
    ans += now;
    ans %= MOD;
    sgn = -sgn;
  }
  cout << ans << endl;
  return 0;
}
