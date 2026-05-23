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
  COMinit();
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int v = 1; v < N; v++) {
    int P;
    cin >> P;
    P--;
    graph.at(P).push_back(v);
  }
  vector<long long> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D.at(i);
  }
  vector<mint> dp(N, 0);
  auto dfs = [&](auto dfs, int u) -> long long {
    long long count = C.at(u);
    for (int v : graph.at(u)) {
      long long now = dfs(dfs, v);
      count += now;
    }
    if (count >= D.at(u)) {
      //dp.at(u) = COM(count, D.at(u));
      dp.at(u) = finv[D.at(u)];
      for (long long a = count - D.at(u) + 1; a <= count; a++) {
        dp.at(u) *= a;
      }
      return count - D.at(u);
    } else {
      dp.at(u) = 0;
      return 0;
    }
  };
  dfs(dfs, 0);
  mint ans = 1;
  for (int u = 0; u < N; u++) {
    ans *= dp.at(u);
  }
  cout << ans << '\n';
  return 0;
}
