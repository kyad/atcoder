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
  int N, X;
  cin >> N >> X;
  vector<int> T(N);
  for (int n = 0; n < N; n++) {
    cin >> T.at(n);
  }
  // dp[i]: i(s)丁度に曲が終わる確率
  vector<Prob> dp(X + 1, 0);  // 1-indexed
  dp[0] = 1;
  Prob p = Prob(1) / N;
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < N; j++) {  // 曲のループ
      if (i + T[j] <= X) {
        dp[i + T[j]] += p * dp[i];
      }
    }
  }
  Prob ans = 0;
  for (int i = max(0, X - T[0] + 1); i <= X; i++) {
    ans += dp[i] * p;
  }
  cout << ans << endl;
  return 0;
}
