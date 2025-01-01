#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int ans = 0;
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  auto f = [&](auto f, int y, int x, int k) -> void {
    if (k == 0) {
      ans++;
      return;
    }
    for (int d = 0; d < 4; d++) {
      int ny = y + dy[d];
      int nx = x + dx[d];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || S.at(ny).at(nx) != '.') {
        continue;
      }
      char prev = S.at(ny).at(nx);
      S.at(ny).at(nx) = '@';
      f(f, ny, nx, k - 1);
      S.at(ny).at(nx) = prev;
    }
  };
  for (int sy = 0; sy < H; sy++) {
    for (int sx = 0; sx < W; sx++) {
      if (S.at(sy).at(sx) != '.') {
        continue;
      }
      S.at(sy).at(sx) = '@';
      f(f, sy, sx, K);
      S.at(sy).at(sx) = '.';
    }
  }
  cout << ans << endl;
  return 0;
}
