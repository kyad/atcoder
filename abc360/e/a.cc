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

using Prob = mint;

int main() {
  int N, K;
  cin >> N >> K;
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  const Prob p = ((Prob)N * (Prob)N - (Prob)N * 2 + (Prob)2) / ((Prob)N * (Prob)N);
  const Prob q = (Prob)2 / ((Prob)N * (Prob)N);
  vector<vector<Prob> > dp(K + 1, vector<Prob>(2, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= K; i++) {
    dp[i][0] = p * dp[i - 1][0] + q * dp[i - 1][1];
    dp[i][1] = 1 - dp[i][0];
  }
  Prob E0 = dp[K][0];
  Prob E1 = dp[K][1] * ((Prob)N + 2) / 2;
  Prob ans = E0 + E1;
  cout << ans << endl;
  return 0;
}
