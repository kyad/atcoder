// https://atcoder.jp/contests/abc088/tasks/abc088_d

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> s(H);
  for (int y = 0; y < H; y++) {
    cin >> s.at(y);
  }
  // BFS
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(H, vector<int>(W, -1));
  todo.push(make_pair(0, 0));
  dist[0][0] = 0;
  while (!todo.empty()) {
    int y = todo.front().first;
    int x = todo.front().second;
    todo.pop();
    const int dy[4] = {-1, 0, 1, 0};
    const int dx[4] = {0, -1, 0, 1};
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        continue;
      }
      if (s[y][x] == '#') {
        continue;
      }
      if (dist[ny][nx] >= 0) {
        continue;
      }
      dist[ny][nx] = dist[y][x] + 1;
      todo.push(make_pair(ny, nx));
    }
  }
  int ans;
  if (dist[H - 1][W - 1] == -1) {
    ans = -1;
  } else {
    int count = 0;
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        if (s[y][x] == '#') {
          count++;
        }
      }
    }
    ans = H * W - count - dist[H - 1][W - 1] - 1;
  }
  cout << ans << endl;
  return 0;
}
