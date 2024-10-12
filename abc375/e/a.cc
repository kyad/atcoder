#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0), B(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
  }
  int S = 0;
  for (int i = 1; i <= N; i++) {
    S += B.at(i);
  }
  if (S % 3 != 0) {
    cout << -1 << endl;
    return 0;
  }
  int M = S / 3;
  const int INF = 1e9;
  vector<vector<vector<int> > > dp(N + 1, vector<vector<int> >(M + 1, vector<int>(M + 1, INF)));
  dp[0][0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      for (int k = 0; k <= M; k++) {
        {
          // 人iを0に入れる
          int nj = j + B.at(i);
          int add = A.at(i) != 0;
          if (nj <= M) {
            chmin(dp[i][nj][k], dp[i - 1][j][k] + add);
          }
        }
        {
          // 人iを1に入れる
          int nk = k + B.at(i);
          int add = A.at(i) != 1;
          if (nk <= M) {
            chmin(dp[i][j][nk], dp[i - 1][j][k] + add);
          }
        }
        {
          // 人iを2に入れる
          int add = A.at(i) != 2;
          chmin(dp[i][j][k], dp[i - 1][j][k] + add);
        }
      }
    }
  }
  int ans = dp[N][M][M];
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
