// https://atcoder.jp/contests/abc232/tasks/abc232_e

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2000000;  // n (<= 10^7)
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
  int y1, x1, y2, x2;  // Differ to probrem's difinition
  cin >> y1 >> x1 >> y2 >> x2;
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  COMinit();

  vector<vector<long long> > dpy(K + 1, vector<long long>(3, 0));
  dpy[0][0] = 0;
  dpy[0][1] = 0;
  dpy[0][2] = 1;
  for (int k = 1; k <= K; k++) {
    dpy[k][1] += dpy[k - 1][0] * (H - 2);
    dpy[k][1] %= MOD;
    dpy[k][2] += dpy[k - 1][0];
    dpy[k][2] %= MOD;

    dpy[k][0] += dpy[k - 1][1]; 
    dpy[k][0] %= MOD;
    if (H > 2) {
      dpy[k][1] += dpy[k - 1][1] * (H - 3);
      dpy[k][1] %= MOD;
    }
    dpy[k][2] += dpy[k - 1][1]; 
    dpy[k][2] %= MOD;

    dpy[k][0] += dpy[k - 1][2]; 
    dpy[k][0] %= MOD;
    dpy[k][1] += dpy[k - 1][2] * (H - 2); 
    dpy[k][1] %= MOD;
  }

  vector<vector<long long> > dpx(K + 1, vector<long long>(3, 0));
  dpx[0][0] = 0;
  dpx[0][1] = 0;
  dpx[0][2] = 1;
  for (int k = 1; k <= K; k++) {
    dpx[k][1] += dpx[k - 1][0] * (W - 2);
    dpx[k][1] %= MOD;
    dpx[k][2] += dpx[k - 1][0];
    dpx[k][2] %= MOD;

    dpx[k][0] += dpx[k - 1][1]; 
    dpx[k][0] %= MOD;
    if (W > 2) {
      dpx[k][1] += dpx[k - 1][1] * (W - 3);
      dpx[k][1] %= MOD;
    }
    dpx[k][2] += dpx[k - 1][1]; 
    dpx[k][2] %= MOD;

    dpx[k][0] += dpx[k - 1][2]; 
    dpx[k][0] %= MOD;
    dpx[k][1] += dpx[k - 1][2] * (W - 2); 
    dpx[k][1] %= MOD;
  }

  vector<vector<long long> > dpy_same(K + 1, vector<long long>(2, 0));
  dpy_same[0][0] = 1;
  dpy_same[0][1] = 0;
  for (int k = 1; k <= K; k++) {
    dpy_same[k][1] += dpy_same[k - 1][0] * (H - 1);
    dpy_same[k][1] %= MOD;

    dpy_same[k][0] += dpy_same[k - 1][1] * 1;
    dpy_same[k][0] %= MOD;
    dpy_same[k][1] += dpy_same[k - 1][1] * (H - 2);
    dpy_same[k][1] %= MOD;
  }

  vector<vector<long long> > dpx_same(K + 1, vector<long long>(2, 0));
  dpx_same[0][0] = 1;
  dpx_same[0][1] = 0;
  for (int k = 1; k <= K; k++) {
    dpx_same[k][1] += dpx_same[k - 1][0] * (W - 1);
    dpx_same[k][1] %= MOD;

    dpx_same[k][0] += dpx_same[k - 1][1] * 1;
    dpx_same[k][0] %= MOD;
    dpx_same[k][1] += dpx_same[k - 1][1] * (W - 2);
    dpx_same[k][1] %= MOD;
  }

  long long ans = 0;
  for (int k = 0; k <= K; k++) {
    long long value = 1;
    long long temp;
    temp = (dy == 0 ? dpy_same[k][0] : dpy[k][0]);
    value *= temp;
    value %= MOD;
    temp = (dx == 0 ? dpx_same[K - k][0] : dpx[K - k][0]);
    value *= temp;
    value %= MOD;
    value *= COM(K, k);
    value %= MOD;
    ans += value;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
