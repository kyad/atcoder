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

// n!/(p!q!r!) mod MOD, O(1)
long long comb3(int n, int p, int q) {
  int r = n - p - q;
  long long ans = fac[n];
  ans *= finv[p];
  ans %= MOD;
  ans *= finv[q];
  ans %= MOD;
  ans *= finv[r];
  ans %= MOD;
  return ans;
}

// m^n, O(log n)
long long power(long long m, long long n, int mod) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  long long A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  vector<long long> X(M, 0);
  vector<long long> Y(M, 0);
  for (int m = 0; m < M; m++) {
    cin >> X.at(m) >> Y.at(m);
  }

  // p, q, rはそれぞれ(+A,+B),(+C,+D),(+E,+F)の移動回数
  // (p, q, r) (p+q+r=n) に障害物があるか
  vector<vector<vector<bool> > > obstacle(N + 1, vector<vector<bool> >(N + 1, vector<bool>(N + 1, false)));
  for (int n = 1; n <= N; n++) {
    for (int p = 0; p <= N; p++) {
      for (int q = 0; q <= N; q++) {
        int r = n - p - q;
        if (r < 0) {
          continue;
        }
        for (int m = 0; m < M; m++) {
          long long x = A * p + C * q + E * r;
          long long y = B * p + D * q + F * r;
          if (x == X.at(m) && y == Y.at(m)) {
            obstacle[n][p][q] = true;
          }
        }
      }
    }
  }

  // dp[n][p][q]: ワープをn回繰り返した時、(p, q, r)の移動回数で行けない組合せの数
  vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> > (N + 1, vector<long long>(N + 1, 0)));
  COMinit();
  for (int n = 1; n <= N; n++) {
    for (int p = 0; p <= N; p++) {
      for (int q = 0; q <= N; q++) {
        int r = n - p - q;
        if (r < 0) {
          continue;
        }
        if (obstacle[n][p][q]) {
          dp[n][p][q] = comb3(n, p, q);
        }
        if (n < N) {
          dp[n + 1][p + 1][q] += dp[n][p][q];
          dp[n + 1][p + 1][q] %= MOD;
          dp[n + 1][p][q + 1] += dp[n][p][q];
          dp[n + 1][p][q + 1] %= MOD;
          dp[n + 1][p][q] += dp[n][p][q];
          dp[n + 1][p][q] %= MOD;
        }
      }
    }
  }

  long long ans = power(3, N, MOD);
  for (int p = 0; p <= N; p++) {
    for (int q = 0; q <= N; q++) {
      int r = N - p - q;
      if (r < 0) {
        continue;
      }
      ans += (MOD - dp[N][p][q]);
      ans %= MOD;
    }
  }
  cout << ans <<endl;
  return 0;
}
