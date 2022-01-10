// https://atcoder.jp/contests/dp/tasks/dp_h

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }
  vector<vector<int> > dp(H, vector<int>(W, 0));
  for (int i = H - 1; i >= 0; i--) {
    for (int j = W - 1; j >= 0; j--) {
      if (i == H - 1 && j == W - 1) {  // init
        dp[i][j] = 1;
        continue;
      }
      if (a[i][j] == '#') {
        dp[i][j] = 0;
      } else {
        const int di[2] = {0, 1};
        const int dj[2] = {1, 0};
        for (int k = 0; k < 2; k++) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (ni >= H || nj >= W) {
            continue;
          }
          dp[i][j] += dp[ni][nj];
          dp[i][j] %= MOD;
        }
      }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}
