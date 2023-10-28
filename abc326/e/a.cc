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
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<mint> dp(N + 1, 0);
  const mint p = (mint)1 / N;
  mint sum = 0;
  for (int i = N; i >= 1; i--) {
#if 1
    dp[i] += sum;
#else
    for (int j = i + 1; j <= N; j++) {
      dp[i] += dp[j];
    }
#endif
    dp[i] += A[i];
    dp[i] *= p;
    sum += dp[i];
  }
  mint ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}
