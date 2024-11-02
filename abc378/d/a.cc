#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }

  vector<vector<bool> > seen(H, vector<bool>(W, false));  // 通ったか

  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  long long ans = 0;

  auto dfs = [&](auto dfs, int y, int x, int length) -> void {
    if (length == K) {
      ans++;
      return;
    }
    for (int l = 0; l < 4; l++) {
      int ny = y + dy[l];
      int nx = x + dx[l];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || S.at(ny).at(nx) == '#' || seen.at(ny).at(nx) == true) {
        continue;
      } else {
        seen.at(ny).at(nx) = true;
        dfs(dfs, ny, nx, length + 1);
        seen.at(ny).at(nx) = false;
      }
    }
  };

  for (int y0 = 0; y0 < H; y0++) {
    for (int x0 = 0; x0 < W; x0++) {
      if (S.at(y0).at(x0) == '#') {
        continue;
      }
      seen.at(y0).at(x0) = true;
      dfs(dfs, y0, x0, 0);
      seen.at(y0).at(x0) = false;
    }
  }
  cout << ans << endl;
  return 0;
}

