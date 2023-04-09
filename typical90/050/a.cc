#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

int main() {
  int N, L;
  cin >> N >> L;
  vector<mint> dp(N + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    dp[i] += dp[i - 1];
    if (i - L >= 0) {
      dp[i] += dp[i - L];
    }
  }
  cout << dp[N] << endl;
  return 0;
}
