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
  int N = S.size();
  S.insert(S.begin(), '_');  // 1-indexed
  const int C = 26;
  vector<vector<int> > next(C, vector<int>(N + 1, N + 1));
  for (int n = N - 1; n >= 0; n--) {
    for (int c = 0; c < C; c++) {
      if (S[n + 1] - 'a' == c) {
        next[c][n] = n + 1;
      } else {
        next[c][n] = next[c][n + 1];
      }
    }
  }
  mint ans = 0;
  for (int k = 1; k < N; k++) {
    vector<vector<mint> > dp(N + 1, vector<mint>(N + 1, 0));
    dp[0][k] = 1;
    for (int i = 0; i <= k; i++) {
      for (int j = k; j <= N - 1; j++) {
        for (int c = 0; c < C; c++) {
          int ni = next[c][i];
          int nj = next[c][j];
          if (ni <= k && nj <= N) {
            dp[ni][nj] += dp[i][j];
          }
        }
      }
    }
    for (int j = k + 1; j <= N; j++) {
      ans += dp[k][j];
    }
  }
  cout << ans.val() << endl;
  return 0;
}
