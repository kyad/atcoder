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

const int MAX = 1e7;  // n (<= 10^7)
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
  int X1, X2, X3;
  cin >> X1 >> X2 >> X3;
  COMinit();
  mint ans = 0;
  for (int k = 0; k <= X2 + 1; k++) {
    int l = X2 + 1 - k;
    mint a = COM(X2 + 1, k);
    mint b;
    if (X1 < k) {
      b = 0;
    } else if (k == 1) {
      b = 1;
    } else {
      b = COM(X1 - 1, k - 1);
    }
    mint c;
    if (l == 0) {
      if (X3 == 0) {
        c = 1;
      } else {
        c = 0;
      }
    } else {
      c = COM(X3 + l - 1, l - 1);
    }
    mint now = a * b * c;
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
