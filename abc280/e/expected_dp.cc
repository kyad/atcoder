#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int N, P;
  cin >> N >> P;
  mint p = mint(P) / mint(100);
  mint q = mint(1) - p;
  // dp[i]: 残り体力iに行くまでの攻撃回数の期待値 (i=0, 1, ..., N)
  vector<mint> dp(N + 1, mint(0));
  for (int i = 1; i <= N; i++) {
    dp[i] = q * (dp[i - 1] + 1) + p * (dp[max(0, i - 2)] + 1);
  }
  cout << dp[N].val() << endl;
  return 0;
}
