#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

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

int main() {
  COMinit();
  int N, P;
  cin >> N >> P;
  mint p = mint(P) / mint(100);
  mint q = mint(1) - p;
  // x回の攻撃でぴったりnのダメージを与える確率
  auto prob = [&](int n, int x) {
    int a = n - x;
    int b = 2 * x - n;
    assert(a >= 0);
    assert(b >= 0);
    long long com = COM(x, a);
    mint ans = mint(int(com)) * p.pow(a) * q.pow(b);
    return ans;
  };
  mint ans = 0;
  for (int x = ceildiv(N, 2); x <= N; x++) {
    ans += prob(N, x) * x;
  }
  for (int x = ceildiv(N - 1, 2); x <= N - 1; x++) {
    ans += prob(N - 1, x) * p * (x + 1);
  }
  cout << ans.val() << endl;
  return 0;
}
