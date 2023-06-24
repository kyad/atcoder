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

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<mint> > dp(N, vector<mint>(2));
  dp[0][0] = 1;
  for (int i = 1; i < N; i++) {
    dp[i][0] += dp[i - 1][1];
    dp[i][1] += dp[i - 1][0] * (M - 1);
    dp[i][1] += dp[i - 1][1] * (M - 2);
  }
  mint ans = dp[N - 1][1];
  ans *= M;
  cout << ans << endl;
  return 0;
}
