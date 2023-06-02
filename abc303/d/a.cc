#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  string S;
  cin >> S;
  int N = S.size();
  const long long INF = 4e18;
  // dp[i][j]: i(1-indexed)文字目を表示させるまでの最短時間。j=0:Caps=OFF, j=1:Caps=ON
  vector<vector<long long> > dp(N + 1, vector<long long>(2, INF));
  dp[0][0] = 0;
  dp[0][1] = Z;
  for (int i = 1; i <= N; i++) {
    if (S[i - 1] == 'A') {
      chmin(dp[i][0], dp[i - 1][0] + Y);
      chmin(dp[i][1], dp[i - 1][1] + X);
    } else {
      chmin(dp[i][0], dp[i - 1][0] + X);
      chmin(dp[i][1], dp[i - 1][1] + Y);
    }
    long long n0 = dp[i][1] + Z;
    long long n1 = dp[i][0] + Z;
    chmin(dp[i][0], n0);
    chmin(dp[i][1], n1);
  }
  long long ans = min(dp[N][0], dp[N][1]);
  cout << ans << endl;
  return 0;
}
