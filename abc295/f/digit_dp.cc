// https://atcoder.jp/contests/abc295/tasks/abc295_f

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long f(string S, long long R) {
  int N = S.size();
  vector<int> A;
  while (R > 0) {
    A.push_back(R % 10);
    R /= 10;
  }
  reverse(A.begin(), A.end());
  int M = A.size();
  long long ans = 0;
  for (int si = 0; si <= M - N; si++) {
    // dp[i][j][k]: i(1-indexed)まで見た時の個数
    // j=1はxより小さいことが確定  k=1は0以外を置いていることが確定
    vector<vector<vector<long long> > > dp(M + 1, vector<vector<long long> >(2, vector<long long>(2, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < M; i++) {
      // iのみ1-indexed, 他の変数は0-indexed
      // dpのみ、dp[i]は1個前の値を示す。dp[i+1]とA[i]は同じ時刻の情報を指す
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          for (int d = 0; d <= 9; d++) {
            // i文字目(0-indexed)に置く
            // Check S
            if (si <= i && i < si + N) {
              int s = S.at(i - si) - '0';
              assert(0 <= s && s <= 9);
              if (s != d) {
                continue;
              }
              // Leading 0 check
              if (d == 0 && k == 0) {
                continue;
              }
            }
            int nj = j;
            int nk = k;
            // A以下かどうか確認する
            if (j == 0) {
              if (d > A[i]) {
                continue;
              } else if (d < A[i]) {  // A未満
                nj = 1;
              }
            }
            if (d >= 1) {
              nk = 1;
            }
            dp[i + 1][nj][nk] += dp[i][j][k];
          }
        }
      }
    }
    long long now = dp[M][0][0] + dp[M][1][0] + dp[M][0][1] + dp[M][1][1];
    ans += now;
  }
  return ans;
}

void testcase() {
  string S;
  long long L, R;
  cin >> S >> L >> R;
  long long ans = f(S, R) - f(S, L - 1);
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
