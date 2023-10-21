#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }

  // DFS
  const int dy[8] = { 0, +1, +1, +1,  0, -1, -1, -1};
  const int dx[8] = {+1, +1,  0, -1, -1, -1,  0, +1};
  vector<vector<bool> > seen(H, vector<bool>(W, false));
  int color = 0;

  for (int sy = 0; sy < H; sy++) {
    for (int sx = 0; sx < W; sx++) {
      if (seen[sy][sx]) {
        continue;
      }
      if (S[sy][sx] == '.') {
        seen[sy][sx] = true;
        continue;
      }
      color++;
      stack<pair<int, int> > todo;
      todo.push(make_pair(sy, sx));
      while (!todo.empty()) {
        int y = todo.top().first;
        int x = todo.top().second;
        seen[y][x] = true;
        todo.pop();
        for (int k = 0; k < 8; k++) {
          int ny = y + dy[k];
          int nx = x + dx[k];
          if (ny < 0 || ny >= H || nx < 0 || nx >= W || S[ny][nx] != '#') {
            continue;
          }
          if (seen[ny][nx]) {
            continue;
          }
          todo.push(make_pair(ny, nx));
        }
      }
    }
  }
  int ans = color;
  cout << ans << endl;
  return 0;
}
