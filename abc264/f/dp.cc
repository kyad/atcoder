#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void chmin(long long &a, long long b) { a = min(a, b); }

int main() {
  int H, W;
  cin >> H >> W;
  vector<long long> R(H);
  for (int y = 0; y < H; y++) {
    cin >> R.at(y);
  }
  vector<long long> C(W);
  for (int x = 0; x < W; x++) {
    cin >> C.at(x);
  }
  vector<string> A(H);
  for (int y = 0; y < H; y++) {
    cin >> A.at(y);
  }
  const long long INF = 4e18;
  // dp[i][j][k]: (i, j)に行くまでの最小コスト。
  // k&1=1ならi行が反転している、k&2=2ならj列が反転している場合
  // 0<=i<H, 0<=j<W, 0<=k<4
  vector<vector<vector<long long> > > dp(H, vector<vector<long long> >(W, vector<long long>(4, INF)));
  for (int k = 0; k < 4; k++) {
    dp[0][0][k] = 0;
    if (k & 1) {
      dp[0][0][k] += R[0];
    }
    if (k & 2) {
      dp[0][0][k] += C[0];
    }
  }
  // 配るDP
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int k = 0; k < 4; k++) {
        int color = A[i][j] - '0';
        if (k & 1) { color = 1 - color; }
        if (k & 2) { color = 1 - color; }
        const int di[2] = {1, 0};
        const int dj[2] = {0, 1};
        for (int l = 0; l < 2; l++) {
          int ni = i + di[l];
          int nj = j + dj[l];
          if (ni >= H || nj >= W) {
            continue;
          }
          int nk = k;
          int ncolor = A[ni][nj] - '0';
          if (l == 0) {
            nk &= 2;
            if (k & 2) { ncolor = 1 - ncolor; }
          } else {
            nk &= 1;
            if (k & 1) { ncolor = 1 - ncolor; }
          }
          long long cost = 0;
          if (color != ncolor) {
            if (l == 0) { cost = R[ni]; nk |= 1; }
            else { cost = C[nj]; nk |= 2; }
          }
          chmin(dp[ni][nj][nk], dp[i][j][k] + cost);
        }
      }
    }
  }
  long long ans = *min_element(dp[H - 1][W - 1].begin(), dp[H - 1][W - 1].end());
  cout << ans << endl;
  return 0;
}
