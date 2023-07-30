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
  string S;
  cin >> S;
  const int N = S.size();
  S.insert(S.begin(), '_');  // 1-indexed
  vector<vector<mint> > dp(N + 1, vector<mint>(N + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if (S[i] != '(') {
        const int nj = j - 1;
        if (nj >= 0) {
          dp[i][nj] += dp[i - 1][j];
        }
      }
      if (S[i] != ')') {
        const int nj = j + 1;
        if (nj <= N) {
          dp[i][nj] += dp[i - 1][j];
        }
      }
    }
  }
  cout << dp[N][0] << endl;
  return 0;
}
