// https://www.youtube.com/watch?v=T_ptI5WGA0w

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
  int Q, K;
  cin >> Q >> K;
  // dp[i]: 和がiになる組合せの個数
  vector<mint> dp(K + 1, 0);
  dp[0] = 1;
  for (int q = 0; q < Q; q++) {
    char typ;
    int x;
    cin >> typ >> x;
    if (typ == '+') {
      // 部分和のDPの遷移
      for (int i = K; i >= x; i--) {
        dp[i] += dp[i - x];
      }
    } else {
      // 戻すDP
      for (int i = x; i <= K; i++) {
        dp[i] -= dp[i - x];
      }
    }
    cout << dp[K] << '\n';
  }
  return 0;
}
