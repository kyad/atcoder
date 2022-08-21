#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> G(H);
  for (int y = 0; y < H; y++) {
    cin >> G.at(y);
  }
  vector<vector<bool> > visited(H, vector<bool>(W, false));
  visited[0][0] = 0;
  int y = 0;
  int x = 0;
  while (true) {
    int dx, dy;
    if (G[y][x] == 'U') {
      dx = 0; dy = -1;
    } else if (G[y][x] == 'D') {
      dx = 0; dy = 1;
    } else if (G[y][x] == 'L') {
      dx = -1; dy = 0;
    } else {  // 'R'
      dx = 1; dy = 0;
    }
    int nx = x + dx;
    int ny = y + dy;
    if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
      cout << (y + 1) << ' ' << (x + 1) << endl;
      return 0;
    }
    if (visited[ny][nx] == true) {
      cout << -1 << endl;
      return 0;
    }
    visited[ny][nx] = true;
    y = ny;
    x = nx;
  }
  return 0;
}
