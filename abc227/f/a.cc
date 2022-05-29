// https://atcoder.jp/contests/abc227/tasks/abc227_f

#include <iostream>
#include <vector>
using namespace std;
void chmin(long long &a, long long b) { a = min(a, b); }

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int> > A(H, vector<int>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A[y][x];
    }
  }
  const long long INF = 1000000000LL * (30 + 30) + 1;
  long long ans = INF;
  for (int xy = 0; xy < H; xy++) {
    for (int xx = 0; xx < W; xx++) {
      int X = A[xy][xx];  // 大きい方からK番目がXであるとする
      // dp[y][x][k]: (y, x)までで、大きい方からk個取った時のコストの最小値
      vector<vector<vector<long long> > > dp(H, vector<vector<long long> >(W, vector<long long>(K + 1, INF)));
      if (A[0][0] <= X) {
        dp[0][0][0] = 0;
      }
      if (A[0][0] >= X) {
        dp[0][0][1] = A[0][0];
      }
      for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
          for (int k = 0; k <= K; k++) {
            const int dy[2] = {0, 1};
            const int dx[2] = {1, 0};
            for (int l = 0; l < 2; l++) {
              int ny = y + dy[l];
              int nx = x + dx[l];
              if (ny >= H || nx >= W) {
                continue;
              }
              if (A[ny][nx] <= X) {
                chmin(dp[ny][nx][k], dp[y][x][k]);
              }
              if (A[ny][nx] >= X && k + 1 <= K) {
                chmin(dp[ny][nx][k + 1], dp[y][x][k] + A[ny][nx]);
              }
            }
          }
        }
      }
      chmin(ans, dp[H - 1][W - 1][K]);
    }
  }
  cout << ans << endl;
  return 0;
}
