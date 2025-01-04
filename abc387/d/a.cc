#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int sy = -1, sx = -1;
  int gy = -1, gx = -1;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S.at(y).at(x) == 'S') {
        sy = y; sx = x;
      } else if (S.at(y).at(x) == 'G') {
        gy = y; gx = x;
      }
    }
  }
  assert(sy != -1);
  assert(gy != -1);

  // BFS
  const int dy[4] = { 0, 0,  -1, +1};
  const int dx[4] = {+1,  -1, 0,  0};
  const int INF = 1e9;
  auto f = [&](bool direction) -> int {  // direction: 初手が縦か
    queue<tuple<int, int, bool> > todo;  // (y, x, 縦か)
    vector<vector<int> > dist(H, vector<int>(W, INF));
    dist.at(sy).at(sx) = 0;
    todo.push(make_tuple(sy, sx, direction));
    while (!todo.empty()) {
      auto [y, x, d] = todo.front();
      todo.pop();
      int from = 0, to = 2;
      if (d == true) {
        from = 2; to = 4;
      }
      for (int k = from; k < to; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
          continue;
        }
        // 壁の条件
        if (S.at(ny).at(nx) == '#') {
          continue;
        }
        if (dist.at(ny).at(nx) == INF) {
          dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
          bool nd = !d;
          todo.push(make_tuple(ny, nx, nd));
        }
      }
    }
    return dist.at(gy).at(gx);
  };

  int ans1 = f(false);
  int ans2 = f(true);
  int ans = min(ans1, ans2);
  if (ans == INF) {
    ans = -1;
  }

  cout << ans << endl;
  return 0;
}
