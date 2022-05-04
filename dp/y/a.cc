// https://atcoder.jp/contests/dp/tasks/dp_y

#include <algorithm>
#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

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
  int H, W, N;
  cin >> H >> W >> N;
  COMinit();
  vector<pair<int, int> > RC(N);
  for (int n = 0; n < N; n++) {
    cin >> RC.at(n).first >> RC.at(n).second;
    RC.at(n).first--;
    RC.at(n).second--;
  }
  sort(RC.begin(), RC.end());
  vector<int> R(N), C(N);
  for (int n = 0; n < N; n++) {
    R.at(n) = RC.at(n).first;
    C.at(n) = RC.at(n).second;
  }
  // dp[i]: 最初にぶつかる壁がiである場合の数
  vector<mint> dp(N);
  for (int n = 0; n < N; n++) {
    dp[n] = COM(R[n] + C[n], R[n]);
    for (int m = 0; m < n; m++) {
      dp[n] -= dp[m] * COM(R[n] + C[n] - R[m] - C[m], R[n] - R[m]);
    }
  }
  mint ans = COM(H + W - 2, H - 1);
  for (int n = 0; n < N; n++) {
    ans -= dp[n] * COM(H - 1 - R[n] + W - 1 - C[n], H - 1 - R[n]);
  }
  cout << ans.val() << endl;
  return 0;
}
