#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

const int MAX = 5100;  // n (<= 10^7)
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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  vector<vector<vector<mint> > > dp(3, vector<vector<mint> > (H, vector<mint>(W)));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      const int dy[2] = {-1, 0};
      const int dx[2] = {0, -1};
      // dp1
      for (int k = 0; k < 2; k++) {
        int py = y + dy[k];
        int px = x + dx[k];
        if (py < 0 || px < 0) {
          continue;
        }
        dp[1][y][x] += dp[1][py][px];
        if (S[y][x] == 'Y' && S[py][px] == 'Y') {
          dp[1][y][x] += COM(px + py, px);
        }
      }
      // dp2
      for (int k = 0; k < 2; k++) {
        int py = y + dy[k];
        int px = x + dx[k];
        if (py < 0 || px < 0) {
          continue;
        }
        dp[2][y][x] += dp[2][py][px];
        if (S[y][x] == 'Y' && S[py][px] == 'Y') {
          dp[2][y][x] +=dp[1][py][px] * 2 + COM(px + py, px);
        }
      }
    }
  }
  cout << dp[2][H - 1][W - 1].val() << endl;
  return 0;
}
