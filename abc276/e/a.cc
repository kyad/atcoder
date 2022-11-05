#include <cassert>
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int y = 0; y < H; y++) {
    cin >> C.at(y);
  }
  int sx = -1, sy = -1;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (C[y][x] == 'S') {
        sy = y;
        sx = x;
        break;
      }
    }
    if (sy >= 0) {
      break;
    }
  }
  assert(sy >= 0);
  assert(sx >= 0);
  // DFS
  vector<vector<bool> > seen(H, vector<bool>(W, false));
  stack<tuple<int, int, int, int> > todo; // y, x, py, px
  todo.push(make_tuple(sy, sx, -1, -1));
  const int dy[4] = {0, -1, 0, 1};
  const int dx[4] = {-1, 0, 1, 0};
  bool ans = false;
  while (!todo.empty()) {
    int y = get<0>(todo.top());
    int x = get<1>(todo.top());
    int py = get<2>(todo.top());
    int px = get<3>(todo.top());
    seen[y][x] = true;
    todo.pop();
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || C[ny][nx] == '#') {
        continue;
      }
      if (ny == py && nx == px) {
        continue;
      }
      if (ny == sy && nx == sx) {
        ans = true;
      }
      if (seen[ny][nx]) {
        continue;
      }
      todo.push(make_tuple(ny, nx, y, x));
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
