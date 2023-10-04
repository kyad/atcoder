#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }
template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int y = 0; y < H; y++) {
    cin >> A.at(y);
  }
  const int INF = 1e9;
  // dp[y][x]: (y, x)における高橋くんの点数-青木くんの点数の最適値
  vector<vector<int> > dp(H, vector<int>(W, 0));
  dp[H - 1][W - 1] = 0;

  auto score = [&](int y, int x) {
    if (A[y][x] == '+') {
      return +1;
    } else {
      return -1;
    }
  };

  for (int k = H + W - 3; k >= 0; k--) {
    for (int y = 0; y < H; y++) {
      int x = k - y;
      if (x < 0 || x >= W) {
        continue;
      }
      if (k % 2 == 0) {  // 高橋くんのターン(k->k+1)
        dp[y][x] = INF;
        if (y + 1 <= H - 1) {
          chmin(dp[y][x], dp[y + 1][x] - score(y + 1, x));
        }
        if (x + 1 <= W - 1) {
          chmin(dp[y][x], dp[y][x + 1] - score(y, x + 1));
        }
      } else {  // 高橋くんのターン(k->k+1)
        dp[y][x] = -INF;
        if (y + 1 <= H - 1) {
          chmax(dp[y][x], dp[y + 1][x] + score(y + 1, x));
        }
        if (x + 1 <= W - 1) {
          chmax(dp[y][x], dp[y][x + 1] + score(y, x + 1));
        }
      }
    }
  }
  string ans;
  if (dp[0][0] < 0) {
    ans = "Takahashi";
  } else if (dp[0][0] > 0) {
    ans = "Aoki";
  } else {
    ans = "Draw";
  }
  cout << ans << endl;
  return 0;
}
