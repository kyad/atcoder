// https://atcoder.jp/contests/abc229/tasks/abc229_f

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> B.at(n);
  }
  const long long INF = 1000000000LL * 200000LL * 2LL + 1LL;
  // 0の色が白とする。
  // dp[n][c][c1]: 1の色がc1で、nの色がcの時の、削除する辺の重みの最小値
  // 0=白、1=黒
  vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> >(2, vector<long long>(2, INF)));
  dp[1][0][0] = A[1];
  dp[1][1][1] = 0;
  for (int n = 1; n <= N - 1; n++) {
    for (int c1 = 0; c1 < 2; c1++) {
      for (int c = 0; c < 2; c++) {
        for (int nc = 0; nc < 2; nc++) {
          dp[n + 1][nc][c1] = min(dp[n + 1][nc][c1], dp[n][c][c1] + (nc == c ? B[n] : 0) + (nc == 0 ? A[n + 1] : 0));
        }
      }
    }
  }
  long long ans = INF;
  for (int c1 = 0; c1 < 2; c1++) {
    for (int c = 0; c < 2; c++) {
      ans = min(ans, dp[N][c][c1] + (c == c1 ? B[N] : 0));
    }
  }
  cout << ans << endl;
  return 0;
}
