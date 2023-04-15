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

vector<mint> f(int N, int A, int P) {
  mint prob(1);
  prob /= P;
  vector<vector<mint> > dp(101, vector<mint>(N + 1));
  dp[0][A] = 1;
  for (int i = 0; i <= 99; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 1; k <= P; k++) {
        int nj = min(j + k, N);
        dp[i + 1][nj] += dp[i][j] * prob;
      }
    }
  }
  vector<mint> ans(101);
  ans.at(0) = dp[0][N];  // x == 0
  for (int x = 1; x <= 100; x++) {
    ans.at(x) = dp[x][N] - dp[x - 1][N];
  }
  return ans;
}

int main() {
  int N, A, B, _p, _q;
  cin >> N >> A >> B >> _p >> _q;
  
  vector<mint> P = f(N, A, _p);
  vector<mint> Q = f(N, B, _q);
  vector<mint> S(Q);
  for (int i = 1; i <= 100; i++) {
    S[i] += S[i - 1];
  }
  mint ans = P[0];  // x = 0
  for (int x = 1; x <= 100; x++) {
    ans += P[x] * (mint(1) - S[x - 1]);
  }
  cout << ans << endl;
  return 0;
}
