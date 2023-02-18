#include <iostream>
#include <vector>
using namespace std;

const long long M = 400000;  // (N)2*10**5 + (K)2*10**5

const int MAX = 8000001;  // n (<= 10^7)
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
  int N, K;
  cin >> N >> K;
  vector<bool> B(M + 1, false);
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    B.at(A) = true;
  }
  int i = 0;
  vector<int> c(M + 1, -1);
  for (int k = 0; k < K; k++) {
    while (i <= M && B[i] == true) {
      if (c[i] < 0) {
        c[i] = K - k - 1;
      }
      i++;
    }
    // i: k回目で選ばれていない最小の数字
    c[i] = K - k - 1;
    if (i <= M) {
      B[i] = true;  // 次のmexで選ばれる
    }
  }
  long long ans = 0;
  for (int i = 0; i <= M; i++) {
    if (c[i] < 0) {
      continue;
    }
    ans += COM(c[i] + i, i);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
