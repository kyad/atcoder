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

const int MAX = 2001;  // n (<= 10^7)
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
  int N, M, K;
  cin >> N >> M >> K;
  COMinit();
  vector<int> A(N + 1, -1);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  int Z = count(A.begin(), A.end(), 0);
  vector<mint> Q(M + 1, 0);
  // Q[i] = P(A_K>=i)を求める
  for (int i = 1; i <= M; i++) {
    int s = 0;
    for (int n = 1; n <= N; n++) {
      if (A[n] >= i) {
        s++;
      }
    }
    if (N - K + 1 - s <= 0) {
      Q[i] = 1;
      continue;
    }
    for (int j = N - K + 1 - s; j <= Z; j++) {
      mint a = COM(Z, j);
      mint b = power(i - 1, Z - j, MOD);
      mint c = power(M - i + 1, j, MOD);
      mint d = power(M, Z, MOD);
      mint now = a * b * c / d;
      Q[i] += now;
    }
  }
  mint ans = 0;
  for (int i = 1; i <= M; i++) {
    ans += Q[i];
  }
  cout << ans << endl;
  return 0;
}
