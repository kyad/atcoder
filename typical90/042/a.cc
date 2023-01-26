#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int K;
  cin >> K;
  vector<vector<mint> > dp(K + 1, vector<mint>(9));
  dp[0][0] = 1;
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j < 9; j++) {
      for (int d = 1; d <= 9; d++) {
        int pi = i - d;
        if (pi < 0) {
          continue;
        }
        int pj = ((j - d) + 9) % 9;
        dp[i][j] += dp[pi][pj];
      }
    }
  }
  cout << dp[K][0].val() << endl;
  return 0;
}
