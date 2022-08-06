// https://atcoder.jp/contests/abc263/tasks/abc263_e

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;
// Solve ax = 1 mod m  (m != prime is OK), O(log m)
// Solve ay = b mod m --> y = b * x mod m
long long modinv(long long a, long long m = MOD) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) {
    u += m;
  }
  return u;
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N - 1);
  for (int n = 0; n < N - 1; n++) {
    cin >> A.at(n);
  }
  // iからNにたどりつくまでのサイコロを振る回数の期待値
  vector<long long> dp(N, 0);
  // sum[i] = dp[i] + ... + dp[N - 1]
  vector<long long> sum(N + 1, 0);
  for (int i = N - 2; i >= 0; i--) {
    dp[i] = sum[i + 1] - sum[i + A[i] + 1] + MOD;
    dp[i] %= MOD;
    dp[i] *= modinv(A[i]);
    dp[i] %= MOD;
    long long now = (A[i] + 1) * modinv(A[i]);
    now %= MOD;
    dp[i] += now;
    dp[i] %= MOD;
    sum[i] = sum[i + 1] + dp[i];
    sum[i] %= MOD;
  }
  cout << dp[0] << endl;
  return 0;
}
