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

const int MAX = 1000001;  // n (<= 10^7)
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
  int H, W, K;
  cin >> H >> W >> K;
  COMinit();
  mint ans;
  for (int r = 1; r <= H; r++) {
    for (int c = 1; c <= W; c++) {
      mint now;
      for (int i = 0; i < 1<<4; i++) {
        int nr = r;
        int nc = c;
        if (i & 1) {
          nr--;
        }
        if (i & 2) {
          nr--;
        }
        if (i & 4) {
          nc--;
        }
        if (i & 8) {
          nc--;
        }
        if (nr < 0 || nc < 0) {
          continue;
        }
        int sgn = __builtin_parity(i) ? -1 : 1;
        now += COM(nr * nc, K) * sgn;
      }
      now *= (H - r + 1);
      now *= (W - c + 1);
      now *= r;
      now *= c;
      ans += now;
    }
  }
  ans /= COM(H * W, K);
  cout << ans.val() << endl;
  return 0;
}
