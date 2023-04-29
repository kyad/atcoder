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
  long long N;
  cin >> N;
  int A = 0, B = 0, C = 0;
  while (N > 1 && N % 2 == 0) {
    N /= 2;
    A++;
  }
  while (N > 1 && N % 3 == 0) {
    N /= 3;
    B++;
  }
  while (N > 1 && N % 5 == 0) {
    N /= 5;
    C++;
  }
  if (N != 1) {
    cout << 0 << endl;
    return 0;
  }
  vector<vector<vector<vector<mint> > > > dp(61, vector<vector<vector<mint> > > (A + 1, vector<vector<mint> > (B + 1, vector<mint>(C + 1))));
  dp[0][0][0][0] = 1;
  mint p = 1;
  p /= 5;
  for (int i = 0; i < 60; i++) {
    for (int a = 0; a <= A; a++) {
      for (int b = 0; b <= B; b++) {
        for (int c = 0; c <= C; c++) {
          // 2
          if (a + 1 <= A) { 
            dp[i + 1][a + 1][b][c] += dp[i][a][b][c] * p;
          }
          // 3
          if (b + 1 <= B) { 
            dp[i + 1][a][b + 1][c] += dp[i][a][b][c] * p;
          }
          // 4
          if (a + 2 <= A) { 
            dp[i + 1][a + 2][b][c] += dp[i][a][b][c] * p;
          }
          // 5
          if (c + 1 <= C) { 
            dp[i + 1][a][b][c + 1] += dp[i][a][b][c] * p;
          }
          // 6
          if (a + 1 <= A && b + 1 <= B) { 
            dp[i + 1][a + 1][b + 1][c] += dp[i][a][b][c] * p;
          }
        }
      }
    }
  }
  mint ans = 0;
  for (int i = 0; i <= 60; i++) {
    ans += dp[i][A][B][C];
  }
  cout << ans.val() << endl;
  return 0;
}
