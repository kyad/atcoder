// https://atcoder.jp/contests/arc160/editorial/6358

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

int upper_bound(int A) {
  int ans = A;
  while (A > 0) {
    A /= 2;
    ans++;
  }
  ans += 2;  // 念のため
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int M = upper_bound(*max_element(A.begin(), A.end()));
  vector<int> B(M + 1, 0);
  for (int n = 0; n < N; n++) {
    B[A[n]]++;
  }
  vector<vector<mint> > dp(M + 1);
  dp[0] = vector<mint>(1 + 1, 1);  // +1: imos
  for (int i = 0; i < M; i++) {
    int n = dp[i].size() - 1;  // -1: imos
    int nn = (n - 1) / 2 + B[i + 1] + 1;
    dp[i + 1] = vector<mint>(nn + 1, 0); // +1: imos
    for (int j = 0; j < n; j++) {
      int left = B[i + 1];
      int right = B[i + 1] + (j / 2) + 1;
      dp[i + 1][left] += dp[i][j];
      dp[i + 1][right] -= dp[i][j];
    }
    // imos
    for (int nj = 0; nj < nn; nj++) {
      dp[i + 1][nj + 1] += dp[i + 1][nj];
    }
  }
  mint ans = 0;
  for (mint a : dp[M]) {
    ans += a;
  }
  cout << ans.val() << endl;
  return 0;
}
